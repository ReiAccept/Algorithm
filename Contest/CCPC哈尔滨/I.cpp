#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 3,MAXA=1e9;
const int INF=1e9;

int n,ans,cnt;
int a[MAXN];
int b[65];
int sum;

void add_bin(int x) {
    int cur=0;
    while(x) {
        if(x&1) {
            b[cur]++;
        }
        x>>=1;
        cur++;
    }
    cnt=max(cur-1,cnt);
}
int ss[65];

void init() {
    int tot=1;
    ss[0]=tot;
    for(int i=1;i<=63;i++) {
        tot*=2;
        ss[i]=ss[i-1]+tot;
    }
    // for(int i=0;i<=33;i++)cout<<i<<" "<<ss[i]<<endl;
}
void work()
{
    // scanf("%lld", &n);
    cin>>n;
    sum=0;
    ans=0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        sum+=a[i];
        add_bin(a[i]);
    }
    // cnt--;
    int xxx;
    while(sum&&cnt>=0) {
        int x=sum/ss[cnt];
        b[cnt]+=xxx;
        xxx=0;
        int xx=min(x,b[cnt]);
        if(b[cnt]>x) {
            xxx=(b[cnt]-x)*2;
        }
        ans+=xx;
        sum-=xx*ss[cnt];
        cnt--;
    }
    ans+=sum;
    // printf("%lld\n",ans);
    cout<<ans<<endl;
}

signed main()
{
    int T;
    init();
    // scanf("%lld", &T);
    cin>>T;
    // cout<<T<<endl;
    for (int i = 0; i < T; i++)
    {
        work();
        for(int i=0;i<=cnt;i++) {
            b[i]=0;
        }
        cnt=0;
    }
}