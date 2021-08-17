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
const int MAXN=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

bool f[20000005];
int prime[20000005];
int tot;
void get_prime()
{
	for(int i=2;i<=20000003;i++)f[i]=true;
	for(int i=2;i<=20000003;i++)
	{
		if(f[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=20000003;j++)
		{
			f[i*prime[j]]=false;
			if(i%prime[j]==0)break;
		}
	}
}

inline bool isprime(int x)
{
    if(f[x])return true;
    else return false;
}

/*
bool isprime(int a)
{
    if(a==2||a==3)
        return 1;
    if(a==1 || (a%6!=1) && (a%6!=5))
        return 0;
    int temp=sqrt(a);
    for(int i=5;i<=temp;i+=6)
    {
        if(a%i==0||a%(i+2)==0)
            return 0;
    }
    return 1;
}
*/
int n,ans;

void work(int n)
{
    //scanf("%lld",&n); 
    ans=0;
    if(n==0){printf("3\n");return;}
    if(n<0){ans+=abs(n)*2+1;n=abs(n)+1;}
    if(isprime(n))
    {
        printf("%lld\n",ans+1);
        return;
    }
    if(ans) //负数
    {
        if(isprime(n+n+1))
        {
            printf("%lld\n",ans+2);
            return;
        }
    }
    else //正数
    {
        if(isprime(n-1+n) || isprime(n+n+1))
        {
            printf("2\n");
            return;
        }
    }
    //while(n%3)n++;
    for(int i=n+3-(n%3);i<=2e7+3;i+=3)
        {
            if(i%2==0)
            {
                if(isprime(i-1))
                {
                    printf("%lld\n",(i-1)<<1);
                    return;
                }
                if(isprime(i+1))
                {
                    printf("%lld\n",(i+1)<<1);
                    return;
                }
            }
            if(isprime(i-1+i))
            {
                printf("%lld\n",(i<<1)-1);
                return;
            }
            if(isprime(i+1+i))
            {
                printf("%lld\n",((i+1)<<1)-1);
                return;
            }
        }
    return;
}

signed main()
{
    get_prime();
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    scanf("%d",&T);
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n)
        work(Case);
    }
    return 0;
}
