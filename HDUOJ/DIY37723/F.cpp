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
const int MOD=10007;
const int MAXN=(int)5;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

template<typename T, int N = 1> //Start Tamplate
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
T Pow(T a, T b, ll n, ll mod)
{
    for(; n ; n >>= 1){
        if(n&1) b=b*a%mod;//b = b*(n&1 ? a:T(1)) %mod;
        a = a*a%mod;
    }
    return b;
}

int n,x,y;

void work()
{
    if(n==0){
        cout<<1<<endl;
        return;
    }else if(n==1){
        cout<<2<<endl;
        return;
    }
    Matrix<int,MAXN> in,ret(true);
    x%=MOD;y%=MOD;
    in.data[1][1]=1;in.data[1][2]=x*x;in.data[1][3]=y*y;in.data[1][4]=2*x*y;
    in.data[2][1]=0;in.data[2][2]=x*x;in.data[2][3]=y*y;in.data[2][4]=2*x*y;
    in.data[3][1]=0;in.data[3][2]=1  ;in.data[3][3]=0  ;in.data[3][4]=0    ;
    in.data[4][1]=0;in.data[4][2]=x  ;in.data[4][3]=0  ;in.data[4][4]=y    ;
    Matrix<int,MAXN> res=Pow(in,ret,n-1,MOD);
    int ans=0;
    ans=(ans+2*res.data[1][1])%MOD;
    ans=(ans+res.data[1][2])%MOD;
    ans=(ans+res.data[1][3])%MOD;
    ans=(ans+res.data[1][4])%MOD;
    cout<<ans<<endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        while(cin>>n>>x>>y) work();
    }
    return 0;
}
