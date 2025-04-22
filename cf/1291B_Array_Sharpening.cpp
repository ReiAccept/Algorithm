#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,maxi;
int a[300003];
bool l[300003],r[300003];

void Solve()
{
    n=qrd();
    for(int i=0;i<n;i++) a[i]=qrd(),l[i]=r[i]=false;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=i)
        {
            l[i]=true;
            if(i>0 && !l[i-1]) l[i]=false;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>=n-1-i)
        {
            r[i]=true;
            if(i<n-1 && !r[i+1]) r[i]=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(l[i] && r[i])
        {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
