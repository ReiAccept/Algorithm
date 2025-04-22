#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,maxb,minb;
int b[200003];

void Solve()
{
    n=qrd();
    for(int i=1;i<=n;i++) b[i]=qrd();
    sort(b+1,b+1+n);
    cout<<b[n]-b[1]<<" ";
    for(int i=1;i<=n;i++)
    {
        if(b[i]==b[1]) minb++;
        else if(b[i]==b[n]) maxb++;
    }
    if(b[1]!=b[n])cout<<(ll)minb*(ll)maxb<<endl;
    else cout<<(ll)(((ll)n-1)+1)*((ll)n-1)/2<<endl;
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
