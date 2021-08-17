#include<bits/stdc++.h>
#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef unsigned long long ull;
typedef long double real;

const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF

int A,B,res;

void work()
{
	cin>>A>>B;
	if(!A)
    {
		cout<<0<<endl;
		return;
	}
	res=A+3;
	for(int i=(B<2?2-B:0); i<res; i++)
    {
		int b=B+i,a=A,ans=i;
		while(a)
        {
			a/=b;
			++ans;
		}
		if(ans<res)res=ans;
	}
	cout<<res<<endl;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;scanf("%lld",&T);
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
