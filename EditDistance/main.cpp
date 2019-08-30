//
//  main.cpp
//  EditDistance
//
//  Created by 許韋中 on 2019/5/7.
//  Copyright © 2019 許韋中. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s1,s2;
    vector<int>buf;
    getline(cin,s1);
    getline(cin,s2);
    int m[100][100]={0};m[0][0]=0;
    int a1=1,a2=1;
    for(int i=1;i<=s1.size()*2;i+=2)
    {m[i][0]=a1;m[i+1][0]=a1;a1++;}
    for(int i=1;i<=s2.size()*2;i+=2)
    {m[0][i]=a2;m[0][i+1]=a2;a2++;}
    for(int i=1;i<=s1.size()*2;i+=2)
    {
        for(int j=1;j<=s2.size()*2;j+=2)
        {
            if(s1[(i-1)/2]!=s2[(j-1)/2])
                m[i][j]=m[i-1][j-1]+1;
            else
                m[i][j]=m[i-1][j-1]+0;
            m[i+1][j]=m[i+1][j-1]+1;
            m[i][j+1]=m[i-1][j+1]+1;
            buf.push_back(m[i][j]);buf.push_back(m[i+1][j]);buf.push_back(m[i][j+1]);
            sort(buf.begin(),buf.end());
            m[i+1][j+1]=buf[0];
            buf.clear();
        }
    }
    for(int i=0;i<=s1.size()*2;i++)
    {
        for(int j=0;j<=s2.size()*2;j++)
        {
            cout<<" "<<m[i][j];
        }
        cout<<endl;
    }
    return 0;
}
