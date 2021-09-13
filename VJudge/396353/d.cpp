#include<bits/stdc++.h>
using namespace std;
int qrd(){int re=0,ch=getchar();while (ch<'0' || ch>'9') ch=getchar();while (ch>='0' && ch<='9'){re=re*10+ch-'0';ch=getchar();}return re;}

long long n,s;

long long sumx(long long num,long long sum=0)
{
    while(num)
    {
        sum+=(num%10);
        num/=10;
    }
    return sum;
}

long long Solve(long long ans=0,long long sum=0)
{
    cin>>n>>s;
    sum=sumx(n);
    if(sum<=s) return 0;
    for(long long i=1; i<=n && sum>s;i*=10)
    {
        long long x=n/i%10;
        if(!x)continue;
        ans+=(10-x)*i;
        n+=(10-x)*i;
        sum=sumx(n);
    }
    return ans;
}

int main()
{
    int T=qrd();
    while(T--) cout<<Solve()<<endl;
    return 0;
}

//给n,求最小k,使n+k的各位数之和<=s。
