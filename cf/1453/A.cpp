#include<bits/extc++.h>
#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

class Solve{
    private:
    int ans,n,m;
    int a[103],b[103];
    public:
        Solve()
        {
            ans=0,n=0,m=0;
        }
        void run()
        {
            n=read();m=read();
            for(int i=1;i<=n;i++) a[i]=read();
            for(int i=1;i<=m;i++) b[i]=read();
            for(int i = 1; i <=n; i++)
		        for(int j = 1; j <=m; j++)
			        if (a[i] == b[j]) ans++;
        }
        ~Solve()
        {
            cout<<ans<<endl;
        }
};


signed main()
{
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        Solve work;
        //printf("Case #%d: ",Case);
        work.run();
    }
    return 0;
}
//傻逼C++期末考