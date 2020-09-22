#include<bits/stdc++.h>
using namespace std;
int qrd(){int re=0,ch=getchar();while (ch<'0' || ch>'9') ch=getchar();while (ch>='0' && ch<='9'){re=re*10+ch-'0';ch=getchar();}return re;}

long long a,b,x,y,n;

void Solve()
{
    a=qrd();b=qrd();x=qrd();y=qrd();n=qrd();
    if(a>b)
    {
        swap(a,b);
        swap(x,y);
    }
    if(a-n>=x) cout<<(a-n)*b<<endl;
    else cout<<min(x*max(b-n+(a-x),y),max(b-n,y)*max(a-n+min(b-y,n),x))<<endl;
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
