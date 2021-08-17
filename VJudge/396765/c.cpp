#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,res;
int a[53];

void Solve()
{
    n=qrd(),res=0;
    memset(a,0,sizeof(a));
	for(int i=1; i<=n; i++) a[qrd()]++;
	for(int i=2; i<=n*2; i++) 
	{
		int ans=0;
		for(int j=max(i-50,1); j<=50; j++) 
            if(i-j<0 || j>i-j) break; 
            else if(j==i-j) ans+=a[j]/2; 
            else ans+=min(a[j],a[i-j]);
		res=max(res,ans);
	}
	cout<<res<<endl;
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
