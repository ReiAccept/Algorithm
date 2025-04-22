#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n;

void work()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j || j==i%n+1)cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return; 
}

signed main()
{
    int Case = read();
	while(Case--) work();
    return 0;
}
