#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,ans,last=1;
int sum[200005];
string s;

void work()
{
    cin>>s;
	for(int i=1;i<=(int)s.size();i++) sum[i]=sum[i-1]+s[i-1]-'0';
	for(int i=1;i<=(int)s.size();i++)
		for(int j=last;j<=i;j++)
			if(!((sum[i]-sum[j-1])%3))
			{
				last=i+1;
				ans++;
				break;
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
