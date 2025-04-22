#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,jiou;
int a[103];

void Solve()
{
    n=qrd();
    for(int i=1;i<=n;i++) a[i]=qrd();
    jiou=(a[1]%2 +a[2]%2 +a[3]%2)/2;
    for(int i=1;i<=n;i++) 
        if(a[i]%2!=jiou)
        {
            cout<<i<<endl;
            break;
        }
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
