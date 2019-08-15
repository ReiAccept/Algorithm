#include<iostream>
#include<algorithm>

using namespace std;

struct road
{
    int x,y,t;
} r[100003];

int n,m;
int fa[100003];

bool cmp(road a,road b)
{
    return a.t<b.t;
}

int findx(int x)
{
    if(fa[x]!=x)
        fa[x]=findx(fa[x]);
    return fa[x];
}

inline void unionxy(int x,int y)
{
    int fx=findx(x),fy=findx(y);
    if(fx!=fy)
    {
        fa[fx]=fy;
        n--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++)
        cin>>r[i].x>>r[i].y>>r[i].t;
    sort(r+1,r+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        unionxy(r[i].x,r[i].y);
        if(n==1)
        {
            cout<<r[i].t<<endl;
            return 0;
        }
    }
    //cout<<n<<endl;
    cout<<"-1"<<endl;
    return 0;
}
