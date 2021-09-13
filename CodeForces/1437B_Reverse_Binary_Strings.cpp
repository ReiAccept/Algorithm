#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

string s;

void work()
{
    int n=read(),zero=0,one=0;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='1' && s[i-1]=='1')one++;
        if(s[i]=='0' && s[i-1]=='0')zero++;
    }
    cout<<max(one,zero)<<endl;
    return;
}

signed main()
{
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
//连续的0的个数和连续的1的个数的最大值
