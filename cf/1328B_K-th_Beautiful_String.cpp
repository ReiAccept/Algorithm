#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;

int n,k;

void Solve()
{
    cin>>n>>k;
    for(int i=n-1;i>0;i--)
    {
        if(k>n-i) k-=n-i;
		else
        {
			for(int j=1;j<i;j++) putchar('a');
			putchar('b');
			for(int j=i+1;j<n-k+1;j++) std::putchar('a');
			putchar('b');
			for(int j=n-k+2;j<=n;j++) std::putchar('a');
			printf("\n");
            return;
		}
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--) Solve();
    return 0;
}
