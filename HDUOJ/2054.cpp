#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

void trim0(string& b)
{
	int len = b.length();
	if(b.find('.')!=string::npos)
	{
		for(int i=len-1;b[i]=='0';i--) len--;
		b=b.substr(0,len);
	}
	if(b[len-1]=='.') b=b.substr(0,len-1);
}

void work()
{
    string a,b;
    while(cin>>a>>b)
	{
		trim0(a);
		trim0(b);
		if(a==b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    }
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
