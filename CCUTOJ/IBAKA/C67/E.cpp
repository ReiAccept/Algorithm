#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

const int mod=1000000007;

int n,k,r=1,ans;
int a[3000003];

int pow_mod(int a,int b,int  c)  //快速幂取模板子
{
    int ans = 1,base=a;// ans：结果；base：底数
    base = base % c;
    if(b==0)
    {
        return 1%c;// 任意a的0次幂都是1,故直接用1%c即可 
    } 
    while(b)
    {   
        if(b & 1) // 与运算，判断奇偶性
        ans = (ans*base) % c; 
        b = b >> 1;// 右移一位，相当于除2
        base = (base * base) % c; 
    } 
    return ans;
} 

int erfen(int l,int r=n)
{
    int kx=k-a[l];
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(a[mid]>=kx) r=mid;
        else l=mid+1;
    }
    return l;
}

void work()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(int l=1;a[l]<=k && l<=n;l++)
    {
        int r=erfen(l);
        while(a[l]+a[r]>k && r>=l) r--;
        if(r<l)continue;
        //printf("L:%d R:%d ",l,r);
        ans=(pow_mod(2,r-l,mod)+ans)%mod;
        //printf("ANS:%d\n",ans);
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    int T = 1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
