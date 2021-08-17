#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int p;
long long n,r,v,N,now,ans;
struct Node
{
    long long b;
    long long a;
} w[100009];

bool cmp(Node x,Node y)
{
    return x.b<y.b;
}

int main()
{
    freopen("exam.in","r",stdin);
    freopen("exam.out","w",stdout);
    cin>>n>>r>>v;
    for(int i=1; i<=n; i++)
    {
        cin>>w[i].a>>w[i].b;
        now+=w[i].a;
    }
    sort(w+1,w+n+1,cmp);
    N=n*v;
    while(N>now)
    {
        p++;
        if(now+r-w[p].a<=N)
        {
            now+=r-w[p].a;
            ans+=w[p].b*(r-w[p].a);
        }
        else
        {
            ans+=w[p].b*(N-now);
            now=N;
        }
    }
    cout<<ans<<endl;
    return 0;
}
