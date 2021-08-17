#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

ll x;

bool isprime(int a)
{
    if(a==2||a==3)return true;
    if(a==1 || (a%6!=1&&a%6!=5))return false;
    for(int i=5; i<=(int)sqrt(a)+1; i+=6)if(a%i==0||a%(i+2)==0)return false;
    return true;
}

void Solve()
{
    cin>>x;
    int t=(int)sqrt(x);
    if(t==sqrt(x) && isprime(t))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
