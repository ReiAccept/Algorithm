#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,a;

void Solve()
{
    n=qrd();
    for(int i=1;i<=n;i++)
    {
        a=qrd();
        if(a%2) printf("%d ",a);
        else printf("%d ",a-1);
    }
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
