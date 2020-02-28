#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int n,ans1,ans2;
int h[100003],f[100003];

int main()
{
    while(cin>>h[++n]);
    n--;
    for(int i=n;i>=1;i--)
    {
        f[i]=1;
        for(int j=i+1;j<=n;j++)
            if(h[j]<=h[i]) f[i]=max(f[i],f[j]+1);
        ans1=f[i]>ans1?f[i]:ans1;
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)//以i-1结尾的最长上升子序列
    {
        f[i]=1;
        for(int j=1;j<i;j++)
            if(h[j]<h[i])f[i]=max(f[i],f[j]+1);
        ans2=(f[i]>ans2?f[i]:ans2);
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
//Dilworth定理：偏序集的最少反链划分数等于最长链的长度
