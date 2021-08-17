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

string sa,sb;
int a[1003],b[1003];

void work()
{
    cin>>sa>>sb;
    
    mmst0(a);mmst0(b);
    int cnt=max(sa.size(),sb.size());
    for(int i=sa.size()-1;i>=0;i--) a[i]=(int)(sa[sa.size()-1-i]-'0');
    for(int i=sb.size()-1;i>=0;i--) b[i]=(int)(sb[sb.size()-1-i]-'0');
    // cout<<cnt<<endl;
    // for(int i=sa.size()-1;i>=0;i--) cout<<i<<":"<<a[i]<<" ";cout<<endl;
    // for(int i=sb.size()-1;i>=0;i--) cout<<i<<":"<<b[i]<<" ";cout<<endl;
    // cout<<cnt<<endl;
    int addx=0;
    for(int i=0;i<=cnt;i++)
    {
        a[i]+=(b[i]+addx);
        addx=a[i]/10;
        a[i]%=10;
        //for(int i=sa.size()-1;i>=0;i--) cout<<i<<":"<<a[i]<<" ";cout<<endl;
    }
    cout<<sa<<" + "<<sb<<" = ";
    if(a[cnt]) cout<<a[cnt];
    for(int i=cnt-1;i>=0;i--) cout<<a[i];
    cout<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=read();
    for(int Case=1;Case<=T;Case++)
    {
        printf("Case %d:\n",Case);
        work();
        if(Case!=T)cout<<endl;
    }
    return 0;
}
