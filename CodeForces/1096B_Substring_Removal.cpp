#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read()
{
    char c;
    int num,f=1;
    while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;
    num=(int)(c-'0');
    while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');
    return num*f;
}

const int MOD=998244353;

int n;
string str;

void work()
{
    n=read();
    cin>>str;
    bool flag=true;
    ll c1=1,c2=1;
    for(int i=1; i<n; i++)
    {
        if(str[i]==str[i-1]) c1++;
        else
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        printf("%lld\n",((n+1)*n/2)%MOD);
        return;
    }
    for(int i=n-2; i>0; --i)
    {
        if(str[i]==str[i+1]) c2++;
        else break;
    }
    if(str[0]==str[n-1]) printf("%lld\n",((ll)(c1+1)*(ll)(c2+1))%MOD);
    else printf("%lld\n",((ll)c1+(ll)c2+(ll)1)%MOD);
    return ;
}

signed main()
{
    int T=1;//read();
    for(int Case=1; Case<=T; Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
/*
分三种情况
1 所有字母相同
2 头尾字母相同 中间不同
3 头尾不同
所有一样就直接等差数列求和
头尾相同情况下将直接(头+1)×(尾+1)
如果不一样,加法原理:头+尾+1,要么全去头,要么全去尾(可以空串再加一)
*/
