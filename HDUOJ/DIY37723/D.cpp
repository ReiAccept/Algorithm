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
const int MOD=123456789;
const int MAXN=(int)7;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
//Start Tamplate
template<typename T, int N = 1>
struct Matrix
{
    Matrix(int f = 0):n(sizeof(data[0])/sizeof(data[0][0])){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                data[i][j] = 0;
        if(f)
            for(int i = 0; i < n; i++) data[i][i] = T(1);
    }

    Matrix operator * (const Matrix other) const{
        Matrix<T, N> ret;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                ret.data[i][j] = (ret.data[i][j] + data[i][k] * other.data[k][j]%MOD)%MOD;
        return ret;
    }

    Matrix operator + (const Matrix other) const{
        Matrix<T, N> ret;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            ret.data[i][j] = (data[i][j] + other[i][j])%MOD;
        return ret;
    }

    Matrix operator % (const ll MOD){
        return *this;
    }

    T data[N][N];
    int n;

};

template<typename T>
T mul(T a, ll n, ll mod)
{
    T ret(1);
    for(; n ; n >>= 1){
        ret = ret*(n&1 ? a:T(1)) %mod;
        a = a*a%mod;
    }
    return ret;
}
//end Template
const int modulu[MAXN][MAXN] = {
    {1, 2, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 1, 3, 3, 1},
    {0, 0, 0, 1, 2, 1},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 1}
};

int n;

void work()
{
    n=read();
    if(n<=2) cout<<n<<endl;
    else
    {
        Matrix<int,MAXN> a;
        memcpy(a.data,modulu,sizeof(modulu));
        a=mul(a,n-2,MOD);
        cout << (a.data[0][0]*2 + a.data[0][1]*1 + a.data[0][2]*27 + a.data[0][3]*9 + a.data[0][4]*3 + a.data[0][5]*1)%MOD << endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n)
        work();
    }
    return 0;
}
