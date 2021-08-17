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

string key="1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
string str;
int res[5];

int chk(char c)
{
    for(int i=0;i<(int)key.size();i++)if(key[i]==c)return i;
}

void work()
{
    cin>>str;
    for(int i=0;i<(int)str.size();i++)res[i]=chk(str[i]);
    sort(res,res+4);
    printf("U(%c),D(%c),L(%c),R(%c)\n",key[res[0]],key[res[2]],key[res[1]],key[res[3]]);
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
