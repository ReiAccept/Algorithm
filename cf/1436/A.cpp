#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,m;

void work()
{
    n=read();m=read();
    int sum=0;
    for(int i=1;i<=n;i++)sum+=(read());
    if(sum==m)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return; 
}

signed main()
{
    int Case = read();
	while(Case--) work();
    return 0;
}
