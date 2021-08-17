#include<bits/extc++.h>
#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define ull unsigned long long
#define MMST(x,y) memset(x,y,sizeof(x))

using namespace std;
using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,ans;
string s;

void work()
{
    n=read();ans=0;
    for(int tmp=0,num=0,i=1;i<=n;i++)
    {
        getline(cin,s);
        if(s[0]=='b' || s[0]=='c')tmp=1;
        else if(s[0]=='i' || s[0]=='f')tmp=4;
        else if(s[0]=='d' || (s[0]=='l' && s[5]=='l'))tmp=8;
        else if(s[0]=='_' || (s[0]=='l' && s[5]=='d'))tmp=16;
        int l1=(int)s.find("[");
        if(l1!=(int)string::npos)
        {
            int l2=(int)s.find("]");
            for(int i=l1+1;i<l2;i++) num=num*10+s[i]-'0';
        }
        if(num)ans+=(tmp*num);
    }
    cout<<ceil((double)ans/1024)<<endl;
    return;
}

signed main()
{
    //cout<<string::npos<<endl;
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
