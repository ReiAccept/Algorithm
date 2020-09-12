#include<bits/stdc++.h>

using namespace std;

int n;
struct Node
{
    string name;
    int y,m,d,n;
}a[103];

bool cmp(Node a,Node b)
{
    if(a.y!=b.y)return a.y<b.y;
    else if(a.m!=b.m)return a.m<b.m;
    else if(a.d!=b.d)return a.d<b.d;
    else return a.n>b.n;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i].n=i;
        cin>>a[i].name>>a[i].y>>a[i].m>>a[i].d;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        cout<<a[i].name<<endl;
    return 0;
}
