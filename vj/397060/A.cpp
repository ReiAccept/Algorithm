#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int x,y,n;

void Solve()
{
    x=qrd();y=qrd();n=qrd();
    int t=(n-y)/x;
    int k=t*x+y;
    printf("%d\n",k);
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
