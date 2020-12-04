//#include<bits/extc++.h>
//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#define int long long
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read()
{
    char c;
    int num,f=1;
    while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
    num=(int)(c-'0');
    while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
    return num*f;
}

char c,s[5][5];

void work()
{
    memset(s,0,sizeof(s));
    for(int i=0; i<=2; i++)
        for(int j=0; j<=2; j++)
        {
            scanf("%c",&s[i][j]);
            getchar();
        }
    scanf("%c",&c);
    int sum=0;
    for(int i=0; i<=2; i++)
        for(int j=0; j<=2; j++)
            if(s[i][j]==c) sum++;
    if(sum<=1) cout<<"Cannot win!"<<endl;
    else
    {
        if(s[1][1]==c||s[1][1]=='.') cout<<"Kim win!"<<endl;
        else cout<<"Cannot win!"<<endl;
    }
    getchar();
    return;
}

signed main()
{
    int T=read();
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
