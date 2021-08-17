#include<bits/stdc++.h>
using namespace std; 
int n,m;
int vis[10100];
int qian[10100];
int z[10100];
int shu[10100];
int vi[10100];
int o[10100];
void init(){
	memset(vis,0,sizeof(vis));
	memset(qian,0,sizeof(qian));
	memset(z,0,sizeof(z));
	memset(shu,0,sizeof(shu));
//	memset(vis,0,sizeof(vis));
	memset(vi,0,sizeof(vi));
	memset(o,0,sizeof(o));
}
struct node{
	int i;
	int x;
};
int main()
{
	int T ;
	cin>>T;
	while(T--){
		cin>>n>>m;
		init();
		map<string ,int > mp;
		int tot=1;
		for(int i=1;i<=n;i++){
			string str;
			cin>>str;
			str=str+"/";
			string s;
			int flag=0;
			string p;
			for(int j=0;j<str.size();j++){
				if(str[j]=='/'&&flag==0){
					flag=1;
					p=s;
					if(mp[s]==0){
						mp[s]=++tot;
						qian[tot]=1;
						z[tot]=1;
					}
				}
				else if(str[j]=='/'&&flag==1){
					if(mp[s]==0){
						mp[s]=++tot;
						qian[tot]=mp[p];
						z[tot]=1;
						shu[mp[p]]++;
					}
					p=s;
				}
				s+=str[j];
			}	
		}
		for(int i=1;i<=m;i++){
			string str;
			cin>>str;
			str=str+"/";
			string s;
			int flag=0;
			string p;
			for(int j=0;j<str.size();j++){
				if(str[j]=='/'&&flag==0){
					flag=1;
					p=s;
					if(mp[s]==0){
						mp[s]=++tot;
						qian[tot]=1;
						z[tot]=0;
					}
				}
				else if(str[j]=='/'&&flag==1){
					if(mp[s]==0){
						mp[s]=++tot;
						qian[tot]=mp[p];
						z[tot]=0;
						shu[mp[p]]++;
					}
					p=s;
				}
				s+=str[j];
			}	
		}
//		for(int i=1;i<=tot;i++){
//			cout<<i<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=tot;i++){
//			cout<<qian[i]<<" ";
//		}
//		cout<<endl;
//		for(int i=1;i<=tot;i++){
//			cout<<shu[i]<<" ";
//		}
//		cout<<endl;
		queue<node> p;
		int ans=0;
		for(int i=2;i<=tot;i++){
			if(shu[i]==0){
				if(z[i]==1) {
					ans++;	p.push(node{i,z[i]});
				}
			
			}
		}
//		cout<<p.size()<<endl;
//		cout<<ans<<endl;
		while(!p.empty()){
			node t=p.front();
			p.pop();
			vi[qian[t.i]]++;
//			o[qian[t.i]]+=t.x;
//			cout<<t.i<<" "<<t.x<<endl;
			if(vi[qian[t.i]]==shu[qian[t.i]]&&qian[t.i]!=1){
				ans-=shu[qian[t.i]];
				ans++;
				p.push(node{qian[t.i],0});
			}
		}
		cout<<ans<<endl;
	}
}
