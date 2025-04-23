#include<cstdio>
#include<iostream>

using namespace std;

int Case,n,m,cz,x,y;
int val[1003];

int main()
{
	ios::sync_with_stdio(false);
	cin>>Case;
	while(Case--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			val[i]=i;
		for(int i=1;i<=m;i++)
		{
			cin>>cz;
			if(cz==1)
			{
				cin>>x>>y;
				for(int j=1;j<=x;j++)
					val[j]=y;
			}
			else
			{
				cin>>x;
				cout<<val[x]<<endl;
			}
		}
	}
	return 0;
}
