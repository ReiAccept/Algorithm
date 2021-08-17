#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;

bool isprime(int a)
{
    if(a==2||a==3)return true;
    if(a==1 || (a%6!=1&&a%6!=5))return false;
    for(int i=5; i<=(int)sqrt(a)+1; i+=6)if(a%i==0||a%(i+2)==0)return false;
    return true;
}

void work()
{
    while(cin>>n)
    {
        int ans=0;
        for(int i=1;i<=n;i++) if(isprime(read())) ans++;
        cout<<ans<<endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
