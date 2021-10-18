#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int sgn[103],va[103],vb[103],vc[103];
int pwx[103];
int ax,bx,cx;
int t[103];

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
    }
    cx=ax+bx;
    //cout<<"DEBUG: CX: "<<cx<<endl;
    if(cx<0)
    {
        cx=-cx;
        for(int i=0;i<n;i++)sgn[i]=-sgn[i];
    }
    int cnt=cx;
    for(int i=0;i<n;i++)
    {
        t[i]=cnt%2;
        cnt/=2;
    }
    bool f=false;
    for(int i=0;i<n;i++)
    {
        if(!f)
        {
            if(sgn[i]==-1&&t[i])
            {
                f=true;
            }
        }
        else
        {
            if(sgn[i]==1&&!t[i])
            {
                t[i]=1;
                f=false;
            }
            else if(sgn[i]==1&&t[i])t[i]=0;
            else if(sgn[i]==-1)
            {
                if(t[i]==1)
                {
                    t[i]=0;
                    f=false;
                }
                else t[i]=1;
            }
        }
    }
   /* for(int i=0;i<n;i++)
    {
        //printf("DEBUG:%lld %lld %lld %lld\n",cx,rx,cx%rx,cx/rx);
        vc[i]=cx%(sgn[i]<<1);
        //printf("DEBUG: VCI:%lld SHANG%lld CX:%lld\n",vc[i],cx/(sgn[i]*2),cx);
        if(sgn[i]==-1 && vc[i]!=0)
        {
            cx=cx/(sgn[i]*2);
            if(cx==0) break;
            else if(cx<0)cx=cx-1;
            else cx++;
        }
        else
        {
            cx=cx/(sgn[i]*2);
            if(cx==0) break;
        }
    }*/
    for(int i=0;i<n;i++) {
        printf("%lld",t[i]);
       // printf("%lld",abs(vc[i]));
        if(i!=n-1) printf(" ");
    }
    //if(cnt!=0) printf(" 1");
    return 0;
}


