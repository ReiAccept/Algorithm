// 复制来学习的，自己是倍增做的
// https://www.acwing.com/blog/content/18134/

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N],tr[N],n,m;
int lastp[N],ans[N];
struct node{
    int l,r,id;
    bool operator<(const node &t){
        return r<t.r;
    }
}q[N];
bool cmp(node a,node b){
    return a.l<b.l;
}
void add(int x,int c){
    for(int i=x;i<=n;i+=i&-i)tr[i]+=c;
}
int sum(int x){
    int ans=0;
    for(int i=x;i;i-=i&-i)ans+=tr[i];
    return ans;
}
int stk[N],top,p[N];
int lowl[N],lowr[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        while(top>0&& (a[stk[top]]==a[i]||b[stk[top]]<=b[i]) )top--;
        p[i]=stk[top];
        stk[++top]=i;
    }
    for(int i=0;i<m;i++){cin>>q[i].l>>q[i].r;q[i].id=i;}
    sort(q,q+m);

    int j=1;
    for(int i=0;i<m;i++){
        int l=q[i].l,r=q[i].r,id=q[i].id;
        while(j<=r){
            add(p[j]+1,1);
            j++;
        }
        ans[id]=sum(l)-(l-1);
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<'\n';
}