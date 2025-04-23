#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN=1000003;
int n,m;
int day[MAXN];//不要把这个东西定义在函数体内,mgj会爆
int r[MAXN],d[MAXN],s[MAXN],t[MAXN];//第i天可用教室数,租借数量,开始,结束
//int debug_sum;

bool judgemid(int mid)
{
    //printf("%d\n",++debug_sum);
    memset(day,0,sizeof(day));
    for(int i=1;i<=mid;i++)
    {
        day[s[i]]+=d[i];
        day[t[i]+1]-=d[i];
    }
    if(day[1]>r[1]) return true;
    for(int i=2;i<=n;i++)
    {
        day[i]+=day[i-1];
        if(day[i]>r[i]) return true;
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) scanf("%d",r+i);
    for(int i=1; i<=m; i++) scanf("%d%d%d",d+i,s+i,t+i);
    int le=1,ri=m;
    while(le<ri)
    {
        int mid=(le+ri)>>1;
        //printf("%d\n",mid);
        if(judgemid(mid)) ri=mid;
        else le=mid+1;
    }
    if(m!=ri) printf("-1\n%d",ri);
    else printf("0");
    return 0;
}
