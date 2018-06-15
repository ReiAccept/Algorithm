#include<queue>
#include<iostream>

using namespace std;

int n;
long long ans;
priority_queue<int,vector<int>,greater<int> > Q; 

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		Q.push(tmp);
	}
    while(Q.size()!=1)
	{
        int tmp1=Q.top();
        Q.pop();
        int tmp2=Q.top();
        Q.pop();
        Q.push(tmp1+tmp2);
        ans+=tmp1+tmp2;
    }
	cout<<ans<<endl;
    return 0 ;
}
