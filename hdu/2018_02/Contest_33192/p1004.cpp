#include<cstdio>
#include<iostream>
#define N 200010

using namespace std;

int Case,n,m,cz,x,y,t;

struct mdzz
{
    int x,y;
} val[N];

void add(int x,int y)
{
    while(t && x>=val[t].x)
        t--;
    val[++t].x=x;
    val[t].y=y;
}

int ask(int x)
{
    if(x<=val[t].x)
        return val[t].y;
    int l=1,r=t-1,mid;
    while(true)
    {
        mid=(l+r)>>1;//感觉被带坏了,除法拿位运算来玩了
        if(val[mid].x>=x && val[mid+1].x<x)
            return val[mid].y;
        if(val[mid].x<x)
            r=mid-1;
        else
            l=mid+1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>Case;
    while(Case--)
    {
        cin>>n>>m;
        t=0;
        for(int i=n; i; i--)
            add(i,i);
        while(m--)
        {
            cin>>cz>>x;
            if(cz==1)
            {
                cin>>y;
                add(x,y);
            }
            else
                cout<<ask(x)<<endl;
        }
    }
}
