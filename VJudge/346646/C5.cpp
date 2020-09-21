#include<set>
#include<vector>
#include<iostream>

using namespace std;

const int ZZ=100005;

set< pair<int,int> >s[ZZ*2],pre;
vector< pair<int,int> >ans;

int n;
bool flag;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y; cin>>x>>y;
        s[y-x+ZZ].insert({x,y});
    }
    for(int i=1;i<=n;i++)
    {
        int k; cin>>k; k+=ZZ;
        if(!s[k].size()){flag=true;break;}
        int xx=s[k].begin()->first,yy=s[k].begin()->second;
        s[k].erase(s[k].begin());
        if(xx && !pre.count({xx-1,yy})){flag=true;break;}
        if(yy && !pre.count({xx,yy-1})){flag=true;break;}
        pre.insert({xx,yy});
        ans.push_back({xx,yy});
    }
    if(!flag)
    {
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
