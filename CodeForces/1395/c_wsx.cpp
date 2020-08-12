#include<bits/stdc++.h>
#define Mid ((l+r)>>1)
#define lson (rt<<1)
#define rson (rt<<1|1)
#define ll long long
#define ull unsigned long long
#define FILL ""
using namespace std;
const int N=0,M=0;
int read(){
	char c;int num,f=1;
	while(c=getchar(),!isdigit(c))if(c=='-')f=-1;num=c-'0';
	while(c=getchar(), isdigit(c))num=num*10+c-'0';
	return num*f;
}
int pa[209],pb[209];
int a[209][40],b[209][40],n,m,sum;
int vis[209][209]; 
//1表示不能选 
int main()
{
	//freopen(FILL".in","r",stdin);
	//freopen(FILL".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		int x=read(),cnt=32;
		pa[i]=x;
		while(x){
			a[i][cnt--]=x&1;
			x>>=1;
		}
	}
	for(int i=1;i<=m;i++){
		int x=read(),cnt=32;
		pb[i]=x;
		while(x){
			b[i][cnt--]=x&1;
			x>>=1;
		}
	}
	for(int k=0;k<=32;k++){
		//枚举每一位
		int q=1,t;
		for(int i=1;i<=n;i++)if(a[i][k]){
			t=0;
			for(int j=1;j<=m;j++)
				if(b[j][k]==0&&vis[i][j]==0)t=1;
			q&=t;
			//如果q=0表示这一位只能是1，就不用限制了 
		}
		if(q==0)continue;
		for(int i=1;i<=n;i++)if(a[i][k]){
			int f=0;
			for(int j=1;j<=m;j++)
				if(b[j][k]==0&&vis[i][j]==0)f=1;
			//如果这一位可以取到0 
			if(f==1){
				for(int j=1;j<=m;j++)
					vis[i][j]|=(b[j][k]==1); 
			}
			//限制
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j]==0){
				sum|=pa[i]&pb[j];
				break;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}
/*
想要C或起来最小肯定按位递减能0则0
ci不是越小越好
只能按位考虑
每个a，考虑哪个b让他递减0最小 
不可行
从高到低位枚举
如果此位ai为0，那么这个ai可选的b集合不变 
如果为1就删去 
*/ 

