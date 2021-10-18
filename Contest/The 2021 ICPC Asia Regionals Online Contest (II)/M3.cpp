#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int sgn[103],va[103],vb[103],vc[103];
int pwx[103];
int ax,bx,cx;

signed main()
{
    //printf("%lld",pow(2,32));
    scanf("%lld",&n);
    for(int i=0;i<=n+1;i++) pwx[i]=pow(2,i);
    for(int i=0;i<n;i++) scanf("%lld",sgn+i);
    for(int i=0;i<n;i++) scanf("%lld",va+i);
    for(int i=0;i<n;i++) scanf("%lld",vb+i);
    for(int i=0;i<n;i++) {
        int rx=pwx[i] * sgn[i];
        ax+=va[i]*rx;
        bx+=vb[i]*rx;
    }
    cx=ax+bx;
    //printf("DEBUG CX: %lld\n",cx);
    //for(int i=n-1;i>=0;i--) 
    for(int i=0;i<n;i++)
    {
        int rx=(pwx[i] * sgn[i]);
        //rx=abs(rx);
        //printf("DEBUG:%lld %lld %lld %lld\n",cx,rx,cx%rx,cx/rx);
        vc[i]=cx%(sgn[i]*2);
        if(cx<0&&sgn[i]<0&&vc[i]<0)
        {
            cx=cx/(sgn[i]*2);
            if(cx<0)cx=-(abs(cx)+1);
            else cx++;
        }
        else
        {
            cx=cx/(sgn[i]*2);
        }
        if(vc[i]<0) {
            vc[i]=-vc[i];
        }
    }
    for(int i=0;i<n;i++) {
        printf("%lld",vc[i]);
        if(i!=n-1) printf(" ");
    }
    return 0;
}
