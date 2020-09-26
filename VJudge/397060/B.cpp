#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

void Solve()
{
    int ans=0,n=qrd();
    while(n%6==0) ans++,n/=6;
	while(n%3==0) ans+=2,n/=3;
	if(n==1) cout<<ans<<endl;
    else cout<<-1<<endl;

}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
