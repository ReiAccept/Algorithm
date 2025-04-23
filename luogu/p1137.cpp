#include<queue>
#include<vector>
#include<iostream>

using namespace std;

int n,m;
int f[100003],in[100003];
vector<int> grap[100003];
queue<int> q;

//int q_bak[100003],bak;//Debug

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        grap[x].push_back(y);
        in[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!in[i])
        {
            f[i]=1;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int cur=q.front();
        //q_bak[bak++]=cur;
        q.pop();
        for(int i=0;i<grap[cur].size();i++)
        {
            f[grap[cur][i]]=max(f[grap[cur][i]],f[cur]+1);
            in[grap[cur][i]]--;
            if(!in[grap[cur][i]])
            {
                q.push(grap[cur][i]);
            }
        }
    }
    //for(int i=0;i<bak;i++) cout<<q_bak[i]<<" ";
    for(int i=1;i<=n;i++)
        cout<<f[i]<<endl;
    return 0;
}
