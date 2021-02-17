#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define ll long long
//#define int long long
//#define int __int128
//#define int __uint128_t
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace _gnu_pbds;

const int INF=0x3f3f3f3f;

int read()
{
	char c;
	int num,f=1;
	while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
	num=(int)(c-'0');
	while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
	return num*f;
}
void prt(int x)
{
 	if(x<0)
 	{
 		putchar('-');
 		x=-x;
	 }
	 if(x>9)prt(x/10);
	 putchar(x%10+'0');
}

int n,k;
int f[1000010][3],pre[1000010];
char s[1000010];
void work()
{
	n=read();
	k=read();
	scanf("%s",s+1);
	for(int i=0;i<=n;i++)f[i][0]=f[i][1]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+s[i]-'0';
	f[0][0]=f[0][1]=0;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=min(f[i-1][0],f[i-1][1])+(s[i]=='1');
		f[i][1]=min(pre[i-1],f[max(0,i-k)][1]+pre[i-1]-pre[max(0,i-k)])+(s[i]=='0');
	}
	printf("%d\n",min(f[n][0],f[n][1]));
	return;
}

signed main()
{
	int T=read();
	for(int Case=1;Case<=T;Case++)
	{
		//printf("Case #%d: ",Case);
		work();
	}
	return 0;
}

