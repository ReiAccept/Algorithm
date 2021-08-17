#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,a,b,money,note;
int in[10001];
int vis[10001];
int pay[10001];
vector<int> graph[10001];
queue<int>q;

int main()
{
    cin>>n>>m;
    for(int i=0; i<10001; i++)
        pay[i]=100;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        graph[b].push_back(a);
        in[a]++;
    }
    while(true)
    {
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(in[i]==0 && vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
                flag=false;
            }
        }
        if(flag)
            break;
        while(!q.empty())
        {
            int mid=q.front();
            note++;
            q.pop();
            pay[mid]+=money;
            for(int x=0; x<graph[mid].size(); x++)
            {
                int next=graph[mid][x];
                in[next]--;
            }
        }
        money++;
    }
    if(note==n)
    {
        int sum=0;
        for(int h=1; h<=n; h++)
            sum+=pay[h];
        cout<<sum<<endl;
    }
    else
        cout<<"Poor Xed"<<endl;
    return 0;
}

/*
首先构图，若存在条件“a的钱比b多”则从b引一条有向指向a；
 然后拓扑排序，若无法完成排序则表示问题无解（存在圈）；
 若可以得到完整的拓扑序列，则按序列顺序进行递推：
 设f[i]表示第i个人能拿的最少奖金数；
 首先所有f[i]=100（题目中给定的最小值）；
 然后按照拓扑顺序考察每个点i，若存在有向边(j,i)，则表示f[i]必须比f[j]大，因此我们令f[i] = Max { f[i] , f[j]+1 }即可；
 递推完成之后所有f[i]的值也就确定了，而答案就等于f[1]+…+f[n]
 */
