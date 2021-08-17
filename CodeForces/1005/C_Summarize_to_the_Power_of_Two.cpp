#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long

using namespace std;

int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}
 
int n,ans;
int a[120003];
map<int,int>m;
 
void Solve()
{
    n=qrd();
    for(int i=1;i<=n;i++)a[i]=qrd();
    for(int i=1;i<=n;i++)m[a[i]]++;
    for(int i=1;i<=n;i++)
    {
        m[a[i]]--;
        int q=0,flag=true;
        while(1<<q <= a[i])q++;
        while(q<=30 && flag)
        {
            if(m[(1<<q) - a[i]])flag=false;
            q++;
        }
        if(flag)ans++;
        m[a[i]]++;
    }
    printf("%d\n",ans);
}
 
int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}

