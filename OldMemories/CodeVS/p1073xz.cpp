#include<iostream>
using namespace std;
int pre[5001];

int find(int x){
	int r=x;
	while(pre[r]!=r){
		r=pre[r];
	}
	return r;
}

int hebing(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		pre[fx]=fy;
	}
}
int main(){
	int n,m,p;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		pre[i]=i;
	}
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		hebing(a,b);
	}
	int s1,s2;
	for(int i=1;i<=p;i++){
		cin>>s1>>s2;
		if(find(s1)!=find(s2)){
			cout<<"No"<<endl;
		}
		else
			cout<<"Yes"<<endl;
	}
}