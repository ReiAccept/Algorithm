#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

int n,m,cnt=1;
queue<int> q;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)q.push(i);
    while(!q.empty())
    {
        if(cnt==m)
        {
            cnt=1;
            cout<<q.front()<<" ";
            q.pop();
        }
        if(cnt!=m)
        {
            cnt++;
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}
