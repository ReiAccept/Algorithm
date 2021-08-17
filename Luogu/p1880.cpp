#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n,minn=0x3f3f3f,maxn;
int a[203],sum[203];
int f_min[203][203],f_max[203][203];

inline int cost(int i,int j)
{
    return sum[j]-sum[i-1];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n*2;i++) sum[i]=sum[i-1]+a[i];
    //memset(f_min,0x3f,sizeof(f_min));
    for(int len=1;len<n;len++)
    {
        for(int i=1,j=len+1;j<2*n && i<2*n;i++,j++)
        {
            f_min[i][j]=0x3f3f3f;
            for(int k=i;k<j;k++)
            {
                f_max[i][j]=max(f_max[i][j],f_max[i][k]+f_max[k+1][j]+cost(i,j));
                f_min[i][j]=min(f_min[i][j],f_min[i][k]+f_min[k+1][j]+cost(i,j));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,f_max[i][i+n-1]);
        minn=min(minn,f_min[i][i+n-1]);
    }
    cout<<minn<<endl<<maxn<<endl;
    return 0;
}
