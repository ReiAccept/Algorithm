#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))
#define pb(x) push_back(x)

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f,MOD=1e9+7;

int read()
{
    char c;
    int num,f=1;
    while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
    num=(int)(c-'0');
    while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
    return num*f;
}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));} //警告,如非必须(如__int128),请不要使用快写

int n;
int l[600003][2],r[600003][2];;
string c,cx;

void work()
{
    n=read();
    cin>>cx;
    c=' '+cx;
    l[0][1]=l[0][0]=r[n][1]=r[n][0]=0;
    for(int i=1;i<=n;i++)
        if(c[i]=='R')l[i][0]=l[i-1][1]+1,l[i][1]=0;
        else l[i][1]=l[i-1][0]+1,l[i][0]=0;
    for(int i=n-1;i>=0;i--)
        if(c[i+1]=='R') r[i][0]=r[i+1][1]+1,r[i][1]=0;
        else r[i][1]=r[i+1][0]+1,r[i][0]=0;
    for(int i=0;i<=n;i++)
    {
        prt(l[i][1]+r[i][0]+1);
        putchar(' ');
    }
    puts("");
}

signed main()
    {
        //ios::sync_with_stdio(false);cin.tie(NULL);
        int T=read();
        for(int Case=1; Case<=T; Case++)
        {
            //printf("Case #%d: ",Case);
            work();
        }
        return 0;
    }
