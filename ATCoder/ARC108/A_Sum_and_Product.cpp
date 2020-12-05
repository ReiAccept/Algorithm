#include<bits/extc++.h>
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int s,p;

void work()
{
    s=read();p=read();
    for(int i=1;i<=1000050 && i<=s;i++)
        if((s-i)*i==p)
        {
            cout<<"Yes"<<endl;
            return;
        }
    cout<<"No"<<endl;
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
