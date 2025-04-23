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

int y,n;

inline bool isleap(int year)
{
    if ((year%4==0 && year%100!=0) || year%400==0) return true;
    return false;
}

void work()
{
    y=read();n=read();
    while(!isleap(y))y++;
    n--;
    while(n)
    {
        y+=4;
        if(isleap(y))n--;
    }
    cout<<y<<endl;
    return;
}

signed main()
{
    int T=read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
