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

int n,cur,cnt;
string s;
char t[200003];

void work()
{
    n=read();
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
    {
        t[cur++]=s[i];
        if(s[i]=='x')
        {
            if(cur>=3 && t[cur-2]=='o' && t[cur-3]=='f')
            {
                cur-=3;
                cnt+=3;
            }
        }
    }
    cout<<n-cnt<<endl;
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
