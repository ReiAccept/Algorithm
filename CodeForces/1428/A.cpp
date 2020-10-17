#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){
	char c; int num, f = 1;
	while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
	return num * f;
}

void work()
{
    int x1,y1,x2,y2;
    x1=read();y1=read();x2=read();y2=read();
    if(x1==x2)
    {
        cout<<abs(y2-y1)<<endl;
        return;
    }
    else if(y1==y2)
    {
        cout<<abs(x1-x2)<<endl;
        return;
    }
    else
    {
        cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
    }
    return; 
}

signed main()
{
    int Case = read();
	while(Case--) work();
    return 0;
}
