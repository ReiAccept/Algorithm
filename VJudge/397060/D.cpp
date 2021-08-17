#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,k;
int a[200003];

void Solve(ll ans=0)
{
    n=qrd();
    cin>>k;
    set<ll> st;
	for(int i=1;i<=n;i++)
	{
        a[i]=qrd();
        a[i]%=k;
        st.insert(a[i]);
    }
	sort(a+1,a+n+1);
	for(set<ll>::iterator it=st.begin();it!=st.end();it++)
	{
	    if(*it==0) continue;
	    ll num=(upper_bound(a+1,a+n+1,*it)-lower_bound(a+1,a+n+1,*it));
	    ans=max(ans,k-*it+(num-1)*k+1);
	}
	cout<<ans<<endl;
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
