#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,m;
vector<int> a;

int Count(int m) 
{
    vector<int> s(2*n+1);
    int sum=n,result=0,add=0;
    s[sum]=1;
    for(int i=0;i<n;i++) 
    {
        if (a[i]<m) sum--,add-=s[sum];
        else add+=s[sum],sum++;
        result += add;
        s[sum]++;
    }
    return result;
}

void work()
{
    n=read();m=read();
    a=vector<int>(n);
    for(int i=0;i<n;i++) a[i]=read();
    printf("%lld\n",Count(m)-Count(m+1));
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
