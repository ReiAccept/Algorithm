#include<iostream>

using namespace std;

long long T;

long long work(long long a,long long b)
{
    long long ans=0;
    while(a!=b && (a!=0 && b!=0))
    {
        if(a<b) swap(a,b);//b>a
        ans+=(a/b);
        a%=b;
    }
    if(a==0 || b==0) ans--;
    return ans;
}

int main()
{
    freopen("sword.in","r",stdin);
    freopen("sword.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        long long a,b;
        cin>>a>>b;
        cout<<work(a,b)<<endl;
    }
    return 0;
}
