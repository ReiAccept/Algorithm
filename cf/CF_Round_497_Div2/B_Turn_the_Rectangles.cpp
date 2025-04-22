#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int x,y;
}a[100003];

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	int h=max(a[1].x,a[1].y);
	for(int i=1;i<n;i++)
	{
		if(h>=a[i+1].x && h>=a[i+1].y)
		{
			h=max(a[i+1].x,a[i+1].y);
			continue;
		}
		else if(h>=a[i+1].x)
		{
			h=a[i+1].x;
			continue;
		}
		else if(h>=a[i+1].y)
		{
			h=a[i+1].y;
			continue;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
