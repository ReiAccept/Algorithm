#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)2e4+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n,m;
int in[MAXN],res[MAXN];

void work()
{
    while (~scanf("%lld%lld", &n, &m))
    {
        vector<int> v[MAXN];
        int cnt = 0,k=0;
        memset(in, 0, sizeof(in));
        memset(res, 0, sizeof(res));
        for (int from,to,i = 0; i < m; i++)
        {
            from=read(); to=read();
            in[from]++;
            v[to].push_back(from);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (!in[j])
                {
                    cnt++;
                    in[j] = -1;
                    k = j;
                    break;
                }
            int len = (int)v[k].size();
            for (int j = 1; j <= len; j++)
            {
                long index = v[k].at(j - 1);
                in[index]--;
                res[index] = max(res[index], res[k] + 1);
            }
        }
        if (cnt == n)
        {
            int ans = 0;
            for (int i = 1; i <= n; i++) ans += res[i];
            printf("%lld\n", ans + 888 * n);
        }
        else printf("-1\n");
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n)
        work();
    }
    return 0;
}
