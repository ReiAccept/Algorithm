/*
//MDZZ这题有坑，可以不走完全程。
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int m,n,result;
int road[105][20005];
vector<int> mdzz;

int findmax(int x);
bool checkzero(int x);

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&road[i][j]);
    for(int i=0; i<n; i++)
    {
        if(checkzero(i))
            mdzz.push_back(result);
        result+=findmax(i);
    }
    for(int i=0; i<mdzz.size(); i++)
        result=max(result,mdzz[i]);
    printf("%d\n",result);
    return 0;
}

int findmax(int x)
{
    int fuck=0;
    for(int i=0; i<m; i++)
        fuck=max(fuck,road[i][x]);
    return fuck;
}
bool checkzero(int x)
{
    for(int i=0; i<m; i++)
        if(road[i][x]>0)
            return  false;
    return true;
}
*/


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn=20005;
const int maxm=105;
const int inf=1000000010;
int N,M;
int s[maxm][maxn];
int t[maxn],sum[maxn];
struct cmp
{
    bool operator()(int aa,int bb)
    {
        return aa<bb;
    }
};
int main()
{
    scanf("%d%d",&M,&N);
    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            scanf("%d",&s[i][j]);
    for(int i=1; i<=N; i++)//求出每组处在同一纵向的旅游街中的分值最大的旅游街
    {
        priority_queue<int,vector<int>,cmp>q;
        for(int j=1; j<=M; j++)
            q.push(s[j][i]);
        t[i]=q.top();
        q.pop();
    }
    sum[0]=0;
    for(int i=1; i<=N; i++)
        sum[i]=sum[i-1]+t[i];//预处理（计算前缀和）
    int MIN=sum[0],ans=-inf;
    for(int i=1; i<=N; i++)//求最大连续子序列和
    {
        int x=sum[i]-MIN;
        ans=max(x,ans);
        MIN=min(MIN,sum[i]);
    }
    printf("%d\n",ans);
    return 0;
}
