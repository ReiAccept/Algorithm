#include<bits/stdc++.h>
using namespace std;
int qrd(){int re=0,ch=getchar();while (ch<'0' || ch>'9') ch=getchar();while (ch>='0' && ch<='9'){re=re*10+ch-'0';ch=getchar();}return re;}

int a,b;

void Solve()
{
    a=qrd();b=qrd();
    int tmp=abs(b-a),ans=0,cnt;
    for(int k=10;k>=1;k--)
    {
        if(tmp/k)
        {
            cnt=tmp/k;
            ans+=cnt;
            tmp-=cnt*k;
        }
    }
    printf("%d\n",ans);
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
