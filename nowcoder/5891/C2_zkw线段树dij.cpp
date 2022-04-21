#include <bits/stdc++.h>

using namespace std;

int sum,MOD=1e9+7;

int pow(int a, int n, int m)
{
    long long ans = 1;
    while(n){
        if(n&1){
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}
typedef long long ll;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') ch=='-'&&(f=-1),ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}//快速读入
const int N=1e6+10,M=1e7+10,inf=0x3f3f3f3f;
int n,m,tot;
int last[N],dis[N];
struct AC{int v,w,to;}e[M];
void add(int x,int y,int z){e[++tot]=(AC){y,z,last[x]};last[x]=tot;}//加边操作

int t[N<<2],num[N<<2],tn;
void first(){memset(t,0x3f,sizeof t);}
void build(){tn=1;while(tn<n)tn<<=1;--tn;for(int i=1;i<=n;++i)num[i+tn]=i;}
void change(int p,ll k)
{
	p+=tn;t[p]=k,p>>=1;
	while (p){
	if (t[p<<1]<t[p<<1|1]) t[p]=t[p<<1],num[p]=num[p<<1];
	else t[p]=t[p<<1|1],num[p]=num[p<<1|1];p>>=1;
	}
}
//上面为zkw线段树
int main()
{
	n=read(),m=read();int s=1;first();build();//first和build是给线段树赋初值
	for(int i=tot,x,y,z;i<m;++i)x=read(),y=read(),z=1,add(x,y,z),add(y,x,1);
	{
		int x;
		memset(dis,0x3f,(n+1)<<2);dis[s]=0;change(s,0);
		while (t[1]!=inf)
		{
			x=num[1];change(x,inf);
			for(int i=last[x],v=e[i].v;i;i=e[i].to,v=e[i].v)
			if (dis[v]>dis[x]+e[i].w)
				dis[v]=dis[x]+e[i].w,change(v,dis[v]);
		}
	}
    for( int i = 2; i <= n; i++ )
    {
        sum+=(pow(2,dis[i],MOD)%MOD);
        sum%=MOD;
    }
    cout<<(sum)%MOD<<endl;
    return 0;
}


