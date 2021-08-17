#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

ll n,m;

inline ll sum(ll x)
{
    return x*(x-1)/2;
}

void Solve()
{
    cin>>n>>m;
    cout<<(n%m)*sum(n/m+1) + (m-(n%m))*sum(n/m)<<" "<<sum(n-m+1)<<endl;
}
int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
//每组的人数x的时候对数是sum(x) == ((x-1)+1)*(x-1)/2 == x*(x-1)/2;
//分组越平均,对数越少,即最多为m*sum(n/m)但是这会产生问题,每组n/m人后余下的n%m个人人还要分配到每组一个;
//某一组突出程度越高,对数越多,即sum(n-m+1)就是将分组分成1 1 1 ... (m-n+1)
