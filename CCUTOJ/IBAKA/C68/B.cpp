#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int x,y;

int qwq(int n)
{
	if(n%4==1) return 1;
	else if(n%4==2) return n+1;
	else if(n%4==3) return 0;
	else return n;
}

void work()
{
    x=read();y=read();
    if(x==0)
    {
        printf("%lld\n",0^qwq(y));
        return;
    }
    x=qwq(x-1);y=qwq(y);
    printf("%lld\n",x^y);
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
//有点意思,xor的逆运算还是xor,找规律1-n的xor结果
//然后把这两个xor一起特判0就行
