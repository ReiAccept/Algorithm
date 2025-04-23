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

int n,m,g,sum;
int p[13];
struct stu
{
    string s;
    int pts;
}ks[1003];

void work()
{
    while(n=read())
    {
        for(int i=1;i<=n;i++) ks[i].pts=0;
        m=read();g=read();sum=0;
        for(int i=1;i<=m;i++) p[i]=read();
        for(int nx,i=1;i<=n;i++)
        {
            cin>>ks[i].s;
            nx=read();
            while(nx--)ks[i].pts+=p[read()];
            if(ks[i].pts>=g)sum++;
        }
        sort(ks+1,ks+1+n,[](stu a,stu b){
            if(a.pts!=b.pts) return a.pts>b.pts;
            else return a.s<b.s;
            });
        cout<<sum<<endl;
        for(int i=1;i<=n;i++)
        {
            if(ks[i].pts>=g) cout<<ks[i].s<<" "<<ks[i].pts<<endl;
            else break;
        }
    }
    return;
}

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
