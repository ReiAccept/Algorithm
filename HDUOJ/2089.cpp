#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int l,r;

int a[20];
int dp[20][2];

int dfs(int pos,int pre,int sta,bool limit)
{
    if(pos==-1)return 1;
    if(!limit && dp[pos][sta]!=-1)return dp[pos][sta];
    int tmp=0,up=limit?a[pos]:9;
    for(int i=0;i<=up;i++)
    {
        if(i==4 || (pre==6 && i==2))continue;
        tmp+=dfs(pos-1,i,i==6,limit && i==a[pos]);//向当前位的低一位找,当前i就是pre(上一位),sta指明是否为6,限位只存在于当前是最高位,下一位还是最高位的情况
    }
    if(!limit)dp[pos][sta]=tmp;
    return tmp;
}

int solve(int x,int pos=0)
{
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,-1,0,true);//最高位开始,最高位无pre设-1,sta为0,限位
}

void work()
{
    while(~scanf("%d%d",&l,&r) && l+r)
    {
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(r)-solve(l-1));
    }
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
