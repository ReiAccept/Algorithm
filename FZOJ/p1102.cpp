#include<iostream>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

int main()
{
    int n,sum=0,a;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        q.push(a);
    }
    int x,y;
    for(int i=0; i<n-1; i++)
    {
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        sum+=x+y;
        q.push(x+y);
    }
    cout<<sum<<endl;
}
