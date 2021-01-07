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
int fib[30]={0,1,1};

void INIT()
{
    for(int i=3;i<=20;i++) fib[i]=fib[i-2]+fib[i-1];
}

void work()
{
    while(cin>>n)
    {
        if(n<=20)
        {
            printf("%d\n",fib[n]);
            continue;
        }
        else
        {
            double log_s=log10(1.0/sqrt(5.0)) +(double)n*log10((1.0+sqrt(5.0))/2.0);
            int ans_s=(int)(pow(10.0,log_s-(int)log_s+3));
            cout <<ans_s<<endl;
        }
    }
    return;
}
//要用到之前的取对数求前几位的知识,也就是说SectionOne的最后一个,前几位取决于小数
signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    INIT();
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
