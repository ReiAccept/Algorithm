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

int k;
int a[2005];

void work()
{
    k=read();
	if (k & 1)
	{
		cout << "-1"<<endl;
		return;
	}
	memset(a, 0, sizeof a);
	a[1] = 1;
	int cur = 1;
	while (k)
	{
		int c;
		for (c = 1; (1ll << (c + 1)) - 2 <= k; c++);
		cur += c - 1;
		a[cur] = 1;
		k -= (1ll << c) - 2;
	}
	cout<<cur-1<<endl;
	for (int i = 1; i < cur; i++) cout<<a[i]<<" ";
    cout<<endl;
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
