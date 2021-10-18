#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int sgn[103],va[103],vb[103],vc[103],ans[103];
int pwx[103];
int ax,bx,cx;

void paser()
{
    for(int i=0;i<n;i++) {
        if(sgn[i]==1){ //==1
            }
        }else{ //-1
            ans[i]=vc[i]%-2;
        }
    }
}

signed main()
{
    scanf("%lld",&n);
    for(int i=0;i<=n+1;i++) pwx[i]=pow(2,i);
    for(int i=0;i<n;i++) scanf("%lld",&sgn[i]);
    for(int i=0;i<n;i++) scanf("%lld",&va[i]);
    for(int i=0;i<n;i++) scanf("%lld",&vb[i]);
    for(int i=0;i<n;i++) {
        int rx=pwx[i] * sgn[i];
        ax+=va[i]*rx;
        bx+=vb[i]*rx;
        vc[i]=va[i]*rx + vb[i]*rx;
    }
    cx=ax+bx;
    paser();
    //printf("DEBUG CX: %lld\n",cx);
    for(int i=0;i<n;i++) {
        printf("%lld",vc[i]);
        if(i!=n-1) printf(" ");
    }
    return 0;
}

/*
3
-1 -1 -1
1 1 1
1 1 1
*/


