// 复制来学习的，自己是倍增做的
// https://www.acwing.com/blog/content/18134/

#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
using namespace std;
const int N=1e6+10;
struct node{
    int sum,l,r;
}tr[N*20];
int n,a[N],b[N],stk[N],top,m,p[N];
int root[N],idx,x,y,j;
void add(int &u,int uu,int l,int r){
    u=++idx;
    tr[u]=tr[uu];
    tr[u].sum++;
    if(l==r)return;
    int mid=l+r>>1;
    if(j<=mid)add(tr[u].l,tr[uu].l,l,mid);
    else add(tr[u].r,tr[uu].r,mid+1,r);
}
int query(int u,int l,int r){
    if(r<=x)return tr[u].sum;
    int mid=l+r>>1;
    int ans=0;
    ans=query(tr[u].l,l,mid);
    if(x>mid)ans+=query(tr[u].r,mid+1,r);
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        while(top>0&&(a[stk[top]]==a[i]||b[stk[top]]<=b[i]))top--;
        p[i]=stk[top];
        j=p[i];
        add(root[i],root[i-1],0,n);//i比i-1这棵树在top的值多了一个1
        stk[++top]=i;
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;
        //输出y这颗树中小于x的值个数减去
        //x-1这颗树中小于x的值个数
        cout<<query(root[y],0,n)-query(root[x],0,n)<<endl;
    }
}