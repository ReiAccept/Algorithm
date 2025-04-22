#include<bits/stdc++.h>

using namespace std;

int n,m,d,w,h,x,y;
char g[33][33];
string route;

inline int chk(int xr,int yr){
    if(g[xr][yr]=='P') return w;
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>d>>w;
    for(int i=0;i<n;i++) cin>>g[i];
    while(d--)
    {
        cin>>h>>x>>y>>route;
        int dmg=chk(x,y);
        for(int i=0;i<(int)route.size();i++)
        {
            if(route[i]=='W') dmg+=chk(--x,y);
            else if(route[i]=='S') dmg+=chk(++x,y);
            else if(route[i]=='A') dmg+=chk(x,--y);
            else if(route[i]=='D') dmg+=chk(x,++y);
        }
        if(dmg>=h) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
