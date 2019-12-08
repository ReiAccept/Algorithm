#include<bits/stdc++.h>

#define maxn 100003

using namespace std;

struct Node
{
    int x, y;
    int v, i;
} node1[maxn],node2[maxn];

int n,d[maxn];

bool cmp1(Node a,Node b)
{
    return (a.v == b.v && a.i < b.i) || a.v < b.v;
}

bool cmp2(Node a,Node b)
{
    return (a.v == b.v && a.x < b.x) || a.v < b.v;
}

bool cmp3(Node a,Node b)
{
    return a.i < b.i;
}

int main()
{
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>node1[i].x>>node1[i].y;
        node1[i].v=node1[i].y-node1[i].x;
    }
    for(int i=0;i<n;i++)
    {
        cin>>node2[i].v;
        node2[i].i=i;
    }
    sort(node2,node2+n,cmp1);
    sort(node1,node1+n,cmp2);
    for(int i=0; i<n;i++)
    {
        if(node2[i].v!=node1[i].v)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        node1[i].i=node2[i].i;
    }
    sort(node1,node1+n,cmp3);
    memset(d,-1,sizeof(d));
    d[0]=0;
    if(node1[0].x != 0 || node1[0].y != 0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        for(int i=1;i<n; i++)
        {
            int x=node1[i].x,y=node1[i].y;
            if(x>0 && d[x-1]<y)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            if(y > 0 && d[x] < y-1)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            d[x]=y;
        }
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++) cout<<node1[i].x<<" "<<node1[i].y<<endl;
    }
    return 0;
}

