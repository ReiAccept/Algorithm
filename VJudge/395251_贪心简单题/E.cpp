#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll qrd(){ll a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

ll a,b;

void Solve()
{
    a=qrd();b=qrd();
    if(b>a || (a-b)%2) cout<<-1<<endl;
    else cout<<((a-b)>>1)<<" "<<a-((a-b)>>1)<<endl;
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
