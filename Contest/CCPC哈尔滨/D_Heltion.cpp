#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r1,r2,r3;
string s,t;
int cnt[10];
int T,n,m,i,j,q;
int find(string &s,string &t)
{
	int n=s.size(),m=t.size(),i=0;
	for(auto c:t)
	{
		while (i<n&&s[i]!=c) --cnt[s[i++]-'0'];
		if (i==n) return 0;
		++i;
	}
	while (i<n) --cnt[s[i++]-'0'];
	for(i=0;i<10;i++) if (cnt[i]) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while (T--)
	{
		r1=r2=0;
		cin>>s>>t;
		n=s.size(),m=t.size();
		for(auto &x:s) r1=r1*10+(x-'0');
		for(auto &x:t) r2=r2*10+(x-'0');
		ll ans1=r1,ans2=r2;
		ll now=gcd(r1,r2);r1/=now;r2/=now;
		int ctt;
		for(j=0;j<1<<n;j++)
		{
			r3=0;ctt=0;
			memset(cnt,0,sizeof cnt);
			for(i=0;i<n;i++) if (j>>i&1) r3=r3*10+s[i]-'0'; else ++cnt[s[i]-'0'],++ctt;
			//cout<<j<<' '<<r3<<endl;
			if (r3%r1||!r3||(__int128)r3/r1*r2>=1llu<<63) continue;
			ll r4=r3/r1*r2;
			string tar=to_string(r4);
			while (tar.size()+ctt<m) tar='0'+tar;
			if (r3<ans1&&find(t,tar)) ans1=r3,ans2=r4;
		}
		cout<<ans1<<' '<<ans2<<endl;
 
	}
}
// 用来学习 https://codeforces.com/gym/103447/submission/137590725