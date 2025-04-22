#include <iostream>
#include<algorithm>
using namespace std;
int pre[100001];

struct comp{
    int a,b,c; //a,b表示编号，c表示费用
}e[100001];

int find(int x){
    int r=x;
    while(pre[r]!=r){
        r=pre[r];
    }
    int i=x,j;
    while(pre[i]!=r){        //路径压缩算法
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}

int hebing(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        pre[fx]=fy;
    }
}
int cmp(comp s1,comp s2){
    return s1.c<s2.c;
}

int main()
{
    int n,m,l=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        pre[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>e[i].a>>e[i].b>>e[i].c;
    }
    sort(e+1,e+1+m,cmp);
    long long res=0;
    for(int i=1;i<=m;i++){
        if(find(e[i].a)!=find(e[i].b))
        {
            hebing(e[i].a,e[i].b);
            res+=e[i].c;
            l++;   //表示链接在网线数
            if(l==n-1)
                break;
        }
    }
    cout<<res<<endl;
    return 0;
}

