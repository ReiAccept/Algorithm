#include<bits/stdc++.h>
using namespace std;
int n,sgn[110],va[110],vb[110],vc[110];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&sgn[i]);
    for(int i=1;i<=n;i++)scanf("%d",&va[i]);
    for(int i=1;i<=n;i++)scanf("%d",&vb[i]);
    for(int i=1;i<=n;i++)
    {
        vc[i]+=va[i]+vb[i];
        if(vc[i]>=2)
        {
            vc[i+1]+=vc[i]/2;
            vc[i]%=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=n)printf("%d ",vc[i]);
        else if(i==n)printf("%d",vc[i]);
    }
    return 0;
}
