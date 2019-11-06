#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int Max[1000005][21];

int read(){int re=0,ch=getchar();while (ch<'0' || ch>'9') ch=getchar();while (ch>='0' && ch<='9'){re=re*10+ch-'0';ch=getchar();}return re;}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++) Max[i][0]=read();
    for(int j=1;j<=21;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        l=read();r=read();
        int k=log2(r-l+1);
        printf("%d\n",max(Max[l][k],Max[r-(1<<k)+1][k]));
    }
    return 0;
}
//ST表模板题
//MDZZ洛谷,模板题卡常数,非要加一个快读
