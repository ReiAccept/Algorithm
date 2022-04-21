#include<bits/stdc++.h>

using namespace std;

double n,p1,v1,p2,v2,l,r,mid;

double calc(double n,double p,double v)
{
    return min(n-p+n,p+n)/v;
}

void work()
{
    scanf("%lf%lf%lf%lf%lf",&n,&p1,&v1,&p2,&v2);
    double ans=min(calc(n,p1,v1),calc(n,p2,v2));
    if (p1>p2) swap(p1,p2),swap(v1,v2);
    ans=min(ans,max(p2/v2,(n-p1)/v1));
    l=p1,r=p2;
    for(int i=1; i<=100; i++)
    {
        mid=(l+r)/2.0;
        double ans1=calc(mid,p1,v1),ans2=calc(n-mid,p2-mid,v2);
        ans=min(ans,max(ans1,ans2));
        if (ans1>ans2) r=mid;
        else l=mid;
    }
    printf("%.10lf\n",ans);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)work();
}

