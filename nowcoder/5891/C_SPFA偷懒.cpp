#include <bits/stdc++.h>

using namespace std;

int sum,MOD=1e9+7;

long long pow(int base,int p,int K){
	long long ans=1,tmp=base;//从底数开始乘，不停自乘
	while(p!=0){//指数不是0 
		if(p&1){
			ans=(ans%K*tmp%K)%K;
		} 
		tmp=(tmp%K*tmp%K)%K;//自乘
		p=p>>1;//访问下一位 
	} 
	ans=ans%K;
	return ans;
} 

const int INF=2147483647;
const int N=1000005;
int d[N];
vector<pair<int,int>>edge[N];
priority_queue<pair<int,int> >q;
int main()
{
	int n,m,s=1,f,g,w=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&f,&g);
		edge[f].push_back(make_pair(g,w));
	}
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int k=q.top().second;
		if(d[k]!=-q.top().first)
		{
			q.pop();
			continue;
		}
		q.pop();
		for(int i=0;i<(int)edge[k].size();i++)
		{
			int v=edge[k][i].first,u=edge[k][i].second;
			if(d[v]>d[k]+u)
			{
				d[v]=d[k]+u;
				q.push(make_pair(-d[v],v));
			}
		}
	}
    for( int i = 2; i <= n; i++ )
    {
        sum+=(pow(2,d[i],MOD)%MOD);
        sum%=MOD;
    }
    cout<<(sum)%MOD<<endl;
    return 0;
}


