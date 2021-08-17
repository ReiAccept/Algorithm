#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;
const int maxn=1e5+3;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

struct Node
{
    int value,pos;
    bool operator <(const Node &d)const
    {
        return value<d.value;
    }
} node[maxn];

int T,Case,n,m,sum,sum1,ans,ans1,cnt;//cnt->防御个数
int a[maxn],b[maxn];

void work()
{
    n=read();m=read();
    ans=ans1=sum=sum1=cnt=0;
    for(int i=0; i<n; i++)
    {
        a[i]=read();
        sum+=a[i];
    }
    for(int i=0; i<m; i++) node[i].value=read();
    for(int i=0; i<m; i++)
    {
        node[i].pos=read();
        if(!node[i].pos) sum1+=node[i].value;
        if(node[i].pos) b[cnt++]=node[i].value;
    }
    sort(node,node+m);
    sort(a,a+n);
    bool flag=false;
    if(n>=m)
    {
        int i=n-1,j=m-1;
        for(; i>=0&&j>=0; i--)
        {
            if(node[j].value<=a[i]) j--;
            else break;
            if(!j) break;
        }
        if(!j) flag=true;
    }
    if(flag)
    {
        int j=0;
        for(int i=0; i<n&&j<cnt; i++)
            if(a[i]>=b[j])
            {
                j++;
                sum-=a[i];
            }
        if(j!=cnt) flag=0;
        else ans=sum-sum1;
    }
    int i=n-1,j=0;
    for(; i&&j<m; i--)
    {
        if(a[i]>=node[j].value)
        {
            if(!node[j].pos) ans1+=(a[i]-node[j].value);
            j++;
        }
        else break;
    }
    printf("Case %lld: %lld\n",++Case,max(ans,ans1));
    return;
}

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
