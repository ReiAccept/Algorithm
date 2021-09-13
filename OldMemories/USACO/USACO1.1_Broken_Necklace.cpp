/*
ID: sa128471
PROG: beads
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector <char>a;

int fd(int x,int n);

int main()
{
    //freopen("beads.in","r",stdin);
    //freopen("beads.out","w",stdout);
    int n,m,maxs,tmp,maxi;
    string xl;
    cin>>n>>xl;
    for(int i=0;i<3;i++)
        for(int k=0;k<n;k++)//防止读入结束符,采用小于号
            a.push_back(xl[k]);
    maxs=fd(0,n);
    maxi=0;
    for(int i=1;i<n;i++)
    {
        tmp=fd(i,n);
        if(tmp>maxs)
        {
            maxs=tmp;
            maxi=i;
        }
    }
    cout<<maxs<<endl;
    //cout<<maxi<<endl;
    return 0;
}

int fd(int x,int n)
{
    int flag=0;
    char b=a[x];
    if(b=='w')
    {
        for(int i=x;;i++)
        {
            if(a[i]!='w')
            {
                b=a[i];
                break;
            }
        }
    }
    for(int i=x;;i++)
    {
        if(flag>=n)
            break;
        if(a[i]==b || a[i]=='w')
            flag++;
        else
            break;
    }
    b=a[x+n-1];
    if(b=='w')
    {
        for(int i=x+n-1;;i--)
        {
            if(a[i]!='w')
            {
                b=a[i];
                break;
            }
        }
    }
    for(int i=x+n-1;;i--)
    {
        if(flag>=n)
            break;
        if(a[i]==b || a[i]=='w')
            flag++;
        else
            break;
    }
    return flag;
}
