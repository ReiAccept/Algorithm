#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("Yes\n")
#define NOO printf("No\n")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=105;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct ppt
{
    int x1, x2, y1, y2;
} co[MAXN];
struct point
{
    int x, y;
} pos[MAXN];
int n, sum;
int ind[MAXN], link[MAXN];
bool G[MAXN][MAXN];

void topsort()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if (ind[i] == 1)
            q.push(i); //找到入度为 1 的字母
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        sum++; //统计遍历到的字母数
        int temp;
        for(int i = 1; i <= n; i++)
        {
            if (G[i][u])
            {
                temp = i; //确定该字母所对应的数字
                break;
            }
        }
        link[u] = temp;
        for(int i = 1; i <= n; i++)
        {
            if (G[temp][i]) //将与该数字有关的边全部删除
            {
                G[temp][i] = false;
                ind[i]--;
            }
            if (ind[i] == 1)
                q.push(i); //找到入度为 1 的字母
        }
    }
    return;
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
        scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &co[i].x1, &co[i].x2, &co[i].y1, &co[i].y2);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &pos[i].x, &pos[i].y);
        for(int j = 1; j <= n; j++)
        {
            if (pos[i].x >= co[j].x1 && pos[i].x <= co[j].x2 && pos[i].y >= co[j].y1 && pos[i].y <= co[j].y2)
            {
                G[i][j] = true;
                ind[j]++;
            }
        }
    }
    topsort();
    if (sum < n)
        puts("None");
    else
    {
        for(int i = 1; i <= n; i++)
        {
            printf("%c %d\n", 'A' + i - 1, link[i]);
        }
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case #%d: \n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}