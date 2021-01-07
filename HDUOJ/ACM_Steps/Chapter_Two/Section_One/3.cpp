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

int p,q;

void work()
{
    while(cin>>p>>q) cout<<p+q-__gcd(p,q)<<endl;
    return;
}
/*
设p>=q,一个蛋糕,然后把它平均切成p块,接下来的任务就是在把已经切了的蛋糕在切成q块,假设之前没有切过蛋糕肯定是切成q块,但蛋糕上切,我们要得到尽量少的块数就得尽量的的利用这些切过的位置少切几刀,我们最多能用的就是p,q的最大公约数
*/
signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
