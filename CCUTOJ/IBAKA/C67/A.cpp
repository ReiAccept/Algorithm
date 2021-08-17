#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

bool flag=false;
string s;
int ans;

void work()
{
    cin>>s;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]=='1')flag=true;
        if(flag==true && (i==0 || s[i]!=s[i-1]))ans++;
    }
    cout<<ans<<endl;
    return;
}

signed main()
{
    int T = 1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
