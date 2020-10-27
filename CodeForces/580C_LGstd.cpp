#include<bits/stdc++.h>

#define LL long long

using namespace std;

LL n,m,ans,tot,head[200010],val[100010];
struct CCF{
	LL nxt,to;
}e[200010];

inline void add(LL x,LL y){
	e[++tot].to=y;
	e[tot].nxt=head[x];
	head[x]=tot;
}
inline void dfs(LL x,LL fa,LL w){
	bool flag=false;
	for(LL i=head[x];i;i=e[i].nxt)
    {
		LL y=e[i].to;
		if(y==fa)continue;
		flag=true;
        //如果它有儿子，就不是叶子节点
		if(val[y]+w>m)continue; //超过m，不做了
		if(val[y])dfs(y,x,val[y]+w);
		else dfs(y,x,0); //点权为0，连续点权清零
	}
	if(!flag)ans++;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<n;i++){
		LL u,v;
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	dfs(1,0,val[1]);
	cout<<ans<<endl;
    return 0;
}
