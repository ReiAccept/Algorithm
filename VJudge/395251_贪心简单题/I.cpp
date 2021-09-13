#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
ll sum,maxa,x;

void Solve()
{
    n=qrd();
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sum+=x;
        maxa=max(x,maxa);
    }
    if(sum%2 || maxa>sum/2) printf("NO\n");
    else printf("YES\n");
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
//这题有点疑问啊,为什么maxa>=sum/2就不对
//比如测试数据
//2
//2 4
//那也不能为0啊
