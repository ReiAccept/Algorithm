#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(...) emplace_back(__VA_ARGS__)
#define sz(x) ((int)(x.size()))
#define PII pair<int,int>
#define PIS pair<int,string>
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define lowbit(x) (-x&x)
#define YESS puts("Yes")
#define NOO puts("No")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)1e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

// 拿严格鸽的试一下
int n, m;
bool inque[1005][1005];
int col[1005][1005];
int dr[4] = { 0,1,0,1 }; int dc[4] = { 0,0,1,1 };//方向数组
queue<pair<int, int>>que;
int check(int i, int j) {
    // 检查 (i,j)(i+1,j)(i,j+1)(i+1,j+1)是否满足条件,如果满足条件返回相同的颜色
    if (1 <= i && i < n && 1 <= j && j < m) {
        set<int>st;
        for(int k = 0; k < 4; k++)
            if (col[i + dr[k]][j + dc[k]])
                st.insert(col[i + dr[k]][j + dc[k]]);
        if (st.size() == 1)return *st.begin();
        else return 0;
    }
    else return 0;
}
//2*2的格子染色成0
void color(int i, int j) { col[i][j] = col[i + 1][j] = col[i][j + 1] = col[i + 1][j + 1] = 0; }
void push(int i, int j) {
    //放入队列
    for(int k = 0; k < 4; k++) {
        int nr = i + dr[k], nc = j + dc[k];
        if (!inque[nr][nc])que.push({ nr,nc }), inque[nr][nc] = 1;
    }
}
 
struct node { int i, j, k; };

inline void work(signed CASE=1,bool FINAL_CASE=false) {
    cin >> n >> m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) cin >> col[i][j];
 
    vector<node>ans;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)  {
        if (check(i, j)) {
            push(i, j);
            ans.push_back({ i,j,check(i,j) }); color(i, j);//放入答案
        }
    }
 
    while (que.size()) {
        int r = que.front().first, c = que.front().second; que.pop();
        for(int i = r - 1; i <= r + 1; i++)
            for(int j = c - 1; j <= c + 1; j++) {
                //遍历包含(r,c)的2*2网格，其实只有4个，i  = [r-1, r ] j  = [c - 1,c] 即可
                if (check(i, j)) {
                    push(i, j);
                    ans.push_back({ i,j,check(i,j) }); color(i, j);//放入答案
                }
            }
    }
 
    int flag = 0; for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) flag += (!inque[i][j]);
    if (flag)cout << "-1";
    else {
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for(auto x : ans)cout << x.i << " " << x.j << " " << x.k << endl;
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
        if(CASE!=T) {}
    }
    return 0;
}