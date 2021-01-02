#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int ten(int m)
{
    int sum=0;
    while(m)
    {
        sum+=m%10;
        m/=10;
    }
    return sum;
}
 
int twelve(int m)
{
    int sum=0;
    while(m)
    {
        sum+=m%12;
        m/=12;
    }
    return sum;
}
 
int sixteen(int m)
{
    int sum=0;
    while(m)
    {
        sum+=m%16;
        m/=16;
    }
    return sum;
}
 
inline bool equal(int a,int b,int c)
{
    if(a==b && b==c) return true;
    return false;
}

void work()
{
    for(int i=2992;i<=9999;i++)
    {
        if(equal(ten(i),twelve(i),sixteen(i))) cout<<i<<endl;
    }
    return;
}

signed main()
{
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
