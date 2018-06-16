#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int a[10010],b[10010];//a[i]表示第i个宝藏的位置,b[i]表示消失的时间
int d[2][10010][2];

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        int cur=0;
        for(int i=1;i<=n;i++)
            d[0][i][0]=d[0][i][1]=(b[i]>0)?0:(1<<30);
        for(int i=1;i<n;i++)
        {
            cur^=1;//如果k偶数,则k=k+1;若k奇数,则k=k-1,实际上就是如果1就0,如果0就1,滚动数组操作
            for(int j=1;j<=n-i;j++)
            {
                d[cur][j][0]=min(d[cur^1][j+1][0]+a[j+1]-a[j],d[cur^1][j+1][1]+a[j+i]-a[j]);
                d[cur][j][1]=min(d[cur^1][j][0]+a[j+i]-a[j],d[cur^1][j][1]+a[j+i]-a[j+i-1]);
                d[cur][j][0]=d[cur][j][0]<b[j]?d[cur][j][0]:(1<<30); 
                d[cur][j][1]=d[cur][j][1]<b[j+i]?d[cur][j][1]:(1<<30);
            }
        }
        if(min(d[cur][1][0],d[cur][1][1])==(1<<30))
            printf("No solution\n");
        else
            printf("%d\n",min(d[cur][1][0],d[cur][1][1]));
    }
    return 0;
}
/*
题目大意：在一条直线上有n（n<=10000）个点有宝藏，每个点的坐标都是整数，每个宝藏在某个时间到之后都会消失，可以在任何一个点出发，移动一个单位需要一个单位的时间，问最少需要多少时间拿完所有宝藏，如果不能拿完所有的输出No solution。输入按照坐标递增顺序。
a[i]表示第i个宝藏的位置，b[i]表示消失的时间。
首先注意到对于任意区间(i,j)，拿完所有宝藏之后必然在i或j两者之一。所以用d[i][j][0]表示拿完第i个到第j个之间的所有宝藏，且最后位于i，用d[i][j][1]表示拿完第i个到第j个之间的所有宝藏且最后位于j。
程序用滚动数组优化内存消耗，递推是按照区间的宽度递增的顺序，所以也是按照这样滚动的。
状态转移方程：
d[i][j][0]=min { d[i+1][j][0]+a[i+1]-a[i],d[i+1][j][1]+a[i+j]-a[i]}
d[i][j][1]=min { d[i][j-1][0]+a[i+j]-a[i],d[i][j-1][1]+a[i+j]-a[i+j-1]}
在程序中还需要判断递推过程中是否能在消失前到达，不能到达则置为INF。
*/
