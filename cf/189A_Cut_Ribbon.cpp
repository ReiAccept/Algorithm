#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
int a[4],f[4003];

void Solve()
{
    n=qrd();a[1]=qrd();a[2]=qrd();a[3]=qrd();
    memset(f,-1,sizeof(f));
    f[0]=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=a[i];j<=n;j++)
        {
            if(f[j-a[i]]<0)continue;
            f[j]=max(f[j],f[j-a[i]]+1);
        }
    }
    printf("%d\n",f[n]);
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
