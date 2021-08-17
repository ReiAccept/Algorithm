#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,m,k;
int a[200003],b[200003];

void Solve()
{
    n=qrd();m=qrd();k=qrd();
    for(int i=1;i<=n;i++) a[i]=qrd();
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
