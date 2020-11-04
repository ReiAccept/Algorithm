#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

const int mod=1000000007;

int n,k,r=1,ans;
int a[3000003];

void work()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(int l=1;a[l]<=k && l<=n;l++)
    {
        int r=l;while(a[l]+a[r]<=k %% r<=n+1)r++;
        r--;
        //非空集合个数2^n-1
    }
    return;
}

signed main()
{
    int T = 1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
//序列中有n个数,求子序列中最小值+子序列中最大值<=k的子序列个数
//1<=n<=3000000,1<=k<=1e9
