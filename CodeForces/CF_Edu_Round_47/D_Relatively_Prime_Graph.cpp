#include<iostream>

using namespace std;

int n,m,ans;

struct QwQ
{
	int x,y;
}vis[100003];

int exgcd(int a,int b)
{
    if(b==0)
        return a;
    else 
        return exgcd(b,a%b);
}

int main()
{
	cin>>n>>m;
	if(m<n-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i!=j && exgcd(i,j)==1)
			{
				ans++;
				vis[ans].x=i;
				vis[ans].y=j;
			}
			if(ans==m)
				break;
		}
		if(ans==m)
			break;
	}
	if(ans==m)
	{
		cout<<"Possible"<<endl;
		for(int i=1;i<=m;i++)
		{
			cout<<vis[i].x<<" "<<vis[i].y<<endl;
		}
	}
	else
	{
		cout<<"Impossible"<<endl;
	}
	return 0;
}
