#include<iostream>
#include<cstdio>
using namespace std;

int a[100001];

struct tree{
	int l,r;
	long long sum;
}tr[400001];

void build_tree(int x,int y,int i){
	tr[i].l=x;
	tr[i].r=y;
	if(x==y){
		tr[i].sum=a[x];
	}
	else{
		long long mid=(tr[i].l+tr[i].r)/2;
		build_tree(x,mid,i*2);
		build_tree(mid+1,y,i*2+1);
		tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
	}
}

void update_tree(int q,int val,int i){
	if(tr[i].l==q && tr[i].r==q){
		tr[i].sum+=val;
	}
	else{
		long long mid=(tr[i].l+tr[i].r)/2;
		if(q<=mid){
			update_tree(q,val,i*2);
		}
		else if(q>mid){
			update_tree(q,val,i*2+1);
		}
		tr[i].sum=tr[i*2].sum+tr[i*2+1].sum;
	}
}

long long query_tree(int q,int w,int i){
	if(q<=tr[i].l && w>=tr[i].r)
		return tr[i].sum;
	else{
		long long mid=(tr[i].l+tr[i].r)/2;
		if(q>mid){
			return query_tree(q,w,i*2+1);
		}
		else if(w<=mid){
			return query_tree(q,w,i*2);
		}
		else{
			return query_tree(q,w,i*2)+query_tree(q,w,i*2+1);
		}
	}
}

int main(){
	int n,m,q,val,li,ri;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build_tree(1,n,1);
	cin>>m;
	for(int i=1;i<=m;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&q,&val);
			update_tree(q,val,1);
		}
		else{
			scanf("%d%d",&li,&ri);
			printf("%lld\n",query_tree(li,ri,1));
		}
	}
	return 0;
} 
