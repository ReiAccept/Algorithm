#include<iostream>

using namespace std;

int n,m,q,k,cur,tot;
int vis[2333];
string str1,str2;

int main()
{
	cin>>n>>m>>q>>str1>>str2;
	while((k=str1.find(str2,cur))!=-1)
		vis[++tot]=cur=k+1;
	vis[++tot]=0x3f3f3f3f;
	for(int i=1;i<=q;i++)
    {
        int x,y,ans=0;
		cin>>x>>y;
		int tmp=lower_bound(vis,vis+1+tot,x)-vis-1;
		for(int j=tmp+1;vis[j]+m-1<=y && j<=tot;j++)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}



