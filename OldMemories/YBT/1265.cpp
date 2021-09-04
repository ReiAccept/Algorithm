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
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));} //警告,如非必须(如__int128),请不要使用快写

int ans;
int f[205][205];
string s1,s2;

void work()
{
    cin>>s1>>s2;
    for(int i=1;i<=(int)s1.size();i++)
        for(int j=1;j<=(int)s2.size();j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(s1[i-1]==s2[j-1]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    cout<<f[(int)s1.size()][(int)s2.size()]<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
