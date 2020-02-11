#include<cstdio>
#include<iostream>

using namespace std;

struct Node
{
    int l,r;
    char val;
} a[300];

int n,num=1;

int findc(char c)
{
    for(int i=1;i<=num;i++) if(a[i].val==c) return i;
    return 0;
}

void buildt(string s)
{
    int cur=1;
    if(num==1)a[1].val=s[0];
    else cur=findc(s[0]);
    if(s[1]!='*')
    {
        a[cur].l=++num;
        a[a[cur].l].val=s[1];
    }
    if(s[2]!='*')
    {
        a[cur].r=++num;
        a[a[cur].r].val=s[2];
    }
    //printf("%d %d %d",cur,a[cur].l,a[cur].r);
}

void printt(int cur)
{
    cout<<a[cur].val;
    if(a[cur].l)printt(a[cur].l);
    if(a[cur].r)printt(a[cur].r);

}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        string opt;
        cin>>opt;
        buildt(opt);
    }
    printt(1);
    return 0;
}
