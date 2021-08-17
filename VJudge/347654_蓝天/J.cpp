#include<queue>
#include<vector>
#include<iostream>

using namespace std;

int n;
long long s;
priority_queue<int,vector<int>,greater<int> >p;

int main()
{
    cin>>n;
    for(int num,i=0; i<n; i++)
    {
        cin>>num;
        p.push(num);
    }
    while(p.size()>1)
    {
        int x=p.top();
        p.pop();
        int y=p.top();
        p.pop();
        s=s+x+y;
        p.push(x+y);
    }
    cout<<s<<endl;
    return 0;
}
