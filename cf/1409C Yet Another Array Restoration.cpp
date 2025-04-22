#include<bits/stdc++.h>
using namespace std;
int qrd(){int re=0,ch=getchar();while (ch<'0' || ch>'9') ch=getchar();while (ch>='0' && ch<='9'){re=re*10+ch-'0';ch=getchar();}return re;}

int n,x,y;

void Solve()
{
    n=qrd();x=qrd();y=qrd();
    int maxn=0,cha=y-x;
    for(int i=n-1;i>=1;i--)
    {
        if(!(cha%i))
        {
            maxn=cha/i;
            break;
        }
    }
    cha/=maxn;
    for(int i=x+maxn;i<=y-maxn;i+=maxn,n--)printf("%d ",i);
    for(int i=x-maxn;i>0&&n>2;i-=maxn,n--) printf("%d ",i);
    for(int i=y+maxn;n>2;i+=maxn,n--) printf("%d ",i);
    printf("%d %d\n",x,y);
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
