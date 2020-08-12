#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int p[100005],h[100005];
vector<int> edge[100005];
bool a[100005];
int b[100005],k[100005];
void dfs(int x){
	int i;
	a[x]=1;
	b[x]=p[x];
	for(i=0;i<edge[x].size();i++){
		if(!a[edge[x][i]]){
			dfs(edge[x][i]);
			b[x]+=b[edge[x][i]];
		}
	}
}
bool dfs1(int x){
	int i,ret=0;
	bool yes=1;
	a[x]=1;
	for(i=0;i<edge[x].size();i++){
		if(!a[edge[x][i]]){
			yes&=dfs1(edge[x][i]);
			ret+=k[edge[x][i]];
		}
	}
	return yes&(ret>=k[x]-p[x]);
}
int main(){
    int t,kk=0;
    scanf("%d",&t);
    while(t--){
    	int n,m,i;
    	for(i=1;i<=kk;i++){
    		edge[i].clear();
    		a[i]=b[i]=0;
    	}
    	bool no=0;
    	scanf("%d%d",&n,&m);
    	kk=n;
    	for(i=1;i<=n;i++){
    		scanf("%d",&p[i]);
    	}
    	for(i=1;i<=n;i++){
    		scanf("%d",&h[i]);
    	}
    	for(i=1;i<n;i++){
    		int x,y;
    		scanf("%d%d",&x,&y);
    		edge[x].push_back(y);
    		edge[y].push_back(x);
    	}
    	dfs(1);
    	for(i=1;i<=n;i++){
    		k[i]=(b[i]-h[i])/2;
    	}
    	for(i=1;i<=n;i++){
    		if(abs(h[i])>b[i]||(b[i]-h[i])%2){
    			printf("NO\n");
    			no=1;
    			break;
    		}
    	}
    	for(i=1;i<=n;i++){
    		a[i]=0;
    	}
    	if(!no){
    		printf("%s\n",dfs1(1)?"YES":"NO");
    	}
    }
	return 0;
}
