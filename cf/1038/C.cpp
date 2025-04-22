#include<queue>
#include<iostream>

using namespace std;

int n;
long long ans;//不开LL见祖宗

priority_queue<int>a,b;

int main()
{
    cin>>n;
    for(int num,i=1;i<=n;i++)
    {
        cin>>num;
        a.push(num);
    }
    for(int num,i=1;i<=n;i++)
    {
        cin>>num;
        b.push(num);
    }
    for(int i=1; i<=n; i++)
    {
        if(a.empty()||b.empty())
        {
            if(a.empty()) b.pop();
            if(b.empty())
            {
                ans+=a.top();
                //cout<<ans<<endl;
                a.pop();
            }
        }
        else
        {
            if(b.top()>a.top()) b.pop();
            else
            {
                ans+=a.top();
                //cout<<ans<<endl;
                a.pop();
            }
        }
        if(a.empty()||b.empty())
        {
            if(a.empty())
            {
                ans-=b.top();
                //cout<<ans<<endl;
                b.pop();
            }
            if(b.empty()) a.pop();
        }
        else
        {
            if(a.top()>b.top()) a.pop();
            else
            {
                ans-=b.top();
                //cout<<ans<<endl;
                b.pop();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
