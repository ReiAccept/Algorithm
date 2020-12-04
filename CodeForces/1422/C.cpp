#include<bits/extc++.h>
#include<bits/stdc++.h>
#define int long long
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

char s[100003];

int ans,sum,p=1;

void work()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=len;i>=1;i--)
    {
        int num=i*(i-1)/2;
        ans=(ans+(((s[i]-'0')*p)%mod*num)%mod)%mod;
        ans=(ans+((s[i]-'0')*sum)%mod)%mod;
        sum=(sum+((len-i+1)*p)%mod)%mod;
        p=(p*10)%mod;
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
