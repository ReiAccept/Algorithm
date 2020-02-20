#include<iostream>
#include<algorithm>

using namespace std;

struct cust
{
    int t,l,h;
    void read(){cin>>t>>l>>h;}
}a[103];

int Q,n,m;

bool check1()
{
    int l=1,r=n;
    while(l<n)
    {
        r=n;
        for(int i=l+1;l<=n;l++)
        {
            if(l.t!=a[i].t)
            {
                r=i-1;
                return
            }
        }
        for(int i=l;i<=r;i++)
            for(int j=l+1;j<=r;j++)
            {
                if(a[i].l>a[i].h)
            }



        l=r+1,r=n;
    }
}
bool checkc()
{
    int ti=0,tm=m;
    for(int i=1;i<=n;i++)
    {
        cust c=a[i];
        if(c.l>tm)
        {
            if(c.t-ti+tm)
        }else if(c.h<tm)
        {

        }
    }
}

int main()
{
    cin>>Q;
    while(Q--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)a[i].read();
    }
    return 0;
}
