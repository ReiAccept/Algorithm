#include<bits/stdc++.h>
// #define int long long
#define double long double
// #define FOR(i,x,y) for(int i=(x),_##i=(y);i<_##i;++i)
using namespace std;

const int MAXN=1e2+5;
const double eps=1E-8;

int n,cnt;
double deta;

double a[MAXN][MAXN];

void gc()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(fabs(a[j][i])>eps)
            {
                for(int k=1;k<=n;k++) swap(a[i][k],a[j][k]);//交换i行和j行
                if(i!=j)cnt++;            
            }
        }
        for(int j=1;j<=n;j++)//消去
        {
            if(i==j)continue;
            double rate=a[j][i]/a[i][i];
            for(int k=i;k<=n;k++)a[j][k]-=a[i][k]*rate;
        }
    }
}
void work() {
    // memset(a,0,sizeof(a));
    // cin>>n>>deta;
    scanf("%d",&n);
    scanf("%llf",&deta);
    cnt=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            // cin>>a[i][j];
            scanf("%llf",&a[i][j]);
        }
    }
    // if(n%2==1) {
    //     printf("+\n");
    // } else {
    //     printf("-\n");
    // }
    // return;
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // guess1();
    gc();
    // cout<<cnt<<endl;
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // bool f=false;
    for(int i=1;i<=n;i++)
    {
        if(a[i][i]<eps)cnt++;
        // if(a[i][i]==eps){
        //     printf("+\n");
        //     return;
        // }
    }
    // if(f)printf("+\n");
    if(cnt%2==0)printf("+\n");
    else printf("-\n");
    return;   
}

signed main() {
    // int T=read();
    int T=1;
    // cin>>T;
    scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    } 
    return 0;
}