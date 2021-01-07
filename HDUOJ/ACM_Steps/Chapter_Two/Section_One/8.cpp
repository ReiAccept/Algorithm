#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;


void work()
{
    n=read();
    double x=n*log10(n);
    x=x-(int)x;
    cout<<(int)pow(10.0,x)<<endl;
    return;
}

/*
    m=n^n;两边同取对数，得到，log10(m)=n*log10(n);
    再得到，m=10^(n*log10(n));
    然后，对于10的整数次幂，第一位是1，
    所以，第一位数取决于n*log10(n)的小数部分
*/

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
