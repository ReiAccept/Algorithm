#include<bits/stdc++.h>
#define int __int128
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
const int N=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int a[N];
void swap1(int n)
{
    int r=n>>1;
    for(int i=1;i<=r;i++) swap(a[i],a[i+r+(n%2)]);
}

void swap2(int n)
{
    for(int i=2;i<=n;i+=2) swap(a[i],a[i-1]);
}

int work(int n)
{
    map<int,int> m;
    for(int i=1;i<=n;i++) a[i]=i;
    while(true)
    {
        int sx=a[1];
        for(int i=2;i<=n;i++) sx=sx*10+a[i];
        if(m[sx]>2) break;
        else m[sx]++;
        //cout<<sx<<" ";
        swap1(n);
        sx=a[1];
        for(int i=2;i<=n;i++) sx=sx*10+a[i];
        if(m[sx]>2) break;
        else m[sx]++;
        //cout<<sx<<" ";
        swap2(n);
    }
    return m.size();
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=(int)read();
    for(signed Case=1; Case<=T; Case+=2)
    {
        //printf("Case %d: ",Case);
        if(Case%2)cout<<"JI ";
        else cout<<"OU ";
        cout<<Case<<" "; prt(work(Case)); cout<<endl;
    }
    return 0;
}