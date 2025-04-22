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

int n,one,two;

void work()
{
    n=read(),one=0,two=0;
    for(int i=1;i<=n;i++)
    {
        if(read()==1)one++;
        else two++;
    }
    if(!(two%2))
    {
        if(!(one%2))
        {
            cout<<"YES"<<endl;
            return ;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
        
    }
    else
    {
        two+=1;
        one-=2;
        if(one<0 || one%2)
        {
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
    }
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
