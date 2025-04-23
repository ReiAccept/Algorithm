#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e5+3;

int n,m;
int a[MAXN],tr[MAXN<<2],tr_max[MAXN<<2];

int read() {
    int x; scanf("%lld",&x);return x;
}

inline void pushup(int rt) {
    int rx=rt<<1;
    tr[rt]=tr[rx]+tr[rx|1];
    tr_max[rt]=max(tr_max[rx],tr_max[rx|1]);
}

void build(int nowl,int nowr,int rt) {
    //nowl->现在的左儿子范围 nowr->现在的右儿子范围 rt->现在指向的节点
    if(nowl==nowr) { //左右指向相同，到达了叶子节点(没有儿子了)
        tr_max[rt]=tr[rt]=a[nowl];
        return;
    }
    int mid=(nowl+nowr)>>1,rx=rt<<1;
    build(nowl,mid,rx); build(mid+1,nowr,rx|1); //递归完成对下方子树的构建
    //解释一下 rx|1，rx在上一句话中左移了一位，所以其二进制的最末尾为 0 ，此时对 1 进行或运算相当于 rx+1
    pushup(rt);
}

void update(int nowl,int nowr,int l,int r,int rt) {
    //nowl->现在的左儿子范围 nowr->现在的右儿子范围 rt->现在指向的节点 l->目标的左边界 r->目标的右边界
    if(nowl>r || nowr<l || tr_max[rt]==1 || tr_max[rt]==0) {
        return;
    }
    if(nowl==nowr) {
        tr[rt]=tr_max[rt]=sqrt(tr_max[rt]); //开平方操作
        return;
    }
    //修改下方子树
    int mid=(nowl+nowr)>>1,rx=rt<<1;
    update(nowl,mid,l,r,rx); update(mid+1,nowr,l,r,rx|1);
    pushup(rt);
}

int qry(int nowl,int nowr,int l,int r,int rt) {
    //和update的变量定义是一样的
    if(nowl>r || nowr<l) {
        return 0;
    }
    if(l<=nowl && r>=nowr) {
        // printf("DEBUG:%lld\n",tr[rt]);
        return tr[rt];
    }
    int mid=(nowl+nowr)>>1,rx=rt<<1;
    return qry(nowl,mid,l,r,rx) + qry(mid+1,nowr,l,r,rx|1);
}

signed main() {
    n=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    m=read();
    build(1,n,1);
    while(m--) {
        int k=read(),l=read(),r=read();
        if(l>r) swap(l,r);
        if(k==0) {
            update(1,n,l,r,1);
        } else if(k==1) {
            printf("%lld\n",qry(1,n,l,r,1));
        }
    }
    return 0;
}

/*
给定一个正整数序列
要求数据结构支持两种操作对序列进行维护
1 修改操作，对区间[L,R]进行开平方
2 查询操作，对区间求一段数的和
$ n,m \leqslant 10^{5} $ 最大值 $ \leqslant 2^{64} $

进行一次开平方的操作，单点时间复杂度为 log级别 ,每次区间修改的复杂度为 $ Nlog $ 级别
每次查询操作，暴力统计为 $ O(N) $ 那么 如果使用前缀和的话是 $ O(1) $
从时间复杂度角度来看 $ M * N log $
假定sqrt为O(1)朴素算法的时间复杂度到达了 $ M*N $ , $ 10 ^{10} $ 显然 TLE

显然我们需要去优化这个算法

用树状结构去优化其查询的过程 ， 查询的过程和区间修改的过程只需要 $ log(N) $即可

### 树状结构的内存消耗
    显然树状结构为等比数列级别的内存消耗，也就是到1*2*2...*2 这样 MAXN*4 (MAXN<<2)

好，我们现在有了最基础的树状结构
也就是有了最简单的线段树 
logN + log(N)*N*(sqrt的复杂度)
也就是说，修改操作成为了我们这棵线段树时间复杂度上的瓶颈

想到修改是一个 sqrt 操作那么显然节点的 val 下降的非常快，很快就会下降到 1 (或者本来就是0)
对 1 或者对 0 做 sqrt 操作是没有意义的 1==sqrt(1) , 0==sqrt(0)
那么显然我们再去维护节点的区间最大值，如果这个节点的区间最大值为 1 或者 0 的情况下，我们就可以直接略过这一步修改
节点最大值为 $ 2^{64} $ ,那么做 64 次 sqrt 操作就 ==1 了
*/