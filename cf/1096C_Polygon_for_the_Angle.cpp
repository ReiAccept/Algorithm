#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int ans[200];

void INIT()
{
    for(int i=3;i<=360;i++)//3-360边型
    {
        for(int j=1;j<=i-2;j++)//选择其中的j条边
        {
            if(180*j%i==0 && !ans[180*j/i]) ans[180*j/i]=i;
        }
    }
}

void work(int n)
{
    printf("%d\n",ans[n]);
    return;
}

signed main()
{
    INIT();
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work(read());
    }
    return 0;
}
//n=360的时候可以等于1-180之间任意的角度,所以上界180下界3
//就是切分圆,求圆所对应的角
//https://www.luogu.com.cn/problem/solution/CF1096C
//杂技找规律打表
