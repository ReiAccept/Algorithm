#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,k,ma;

void Solve()
{
    n=qrd();k=qrd();ma=1;
    if(k>=n)
    {
        printf("1\n");
        return;
    }
    for(int i=(int)sqrt(n+1);i>=1;i--)
        if(!(n%i))
        {
            int a = i, b = n / i;
			if(a <= k) ma = max(ma, a);
			if(b <= k) ma = max(ma, b);
        }
    printf("%d\n",n/ma);
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
