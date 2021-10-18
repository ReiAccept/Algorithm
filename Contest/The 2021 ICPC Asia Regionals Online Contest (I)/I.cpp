#include<bits/stdc++.h>
#define int long long

using namespace std;

int T,cnt;
//double a,b,r;

void work()
{
    int a,b,r;
    //scanf("%lld%lld%lld",&a,&b,&r);
    cin>>a>>b>>r;
    if(b>=r)
    {
        double res=sqrt(4.0*(a*a+(b-r)*(b-r)))-r;
        ++cnt;
        printf("Case #%lld: %.2lf",cnt,res);
        if(T)printf("\n");
    }
    else
    {
        double res=2.0*a-r;
        ++cnt;
        printf("Case #%lld: %.2lf",cnt,res);
        if(T)printf("\n");
    }
}

signed main()
{
    cin>>T;
    //scanf("%lld", &T);
    while(T--) work();
    return 0;
}
/*
2
3 5 1
3 5 1
*/
