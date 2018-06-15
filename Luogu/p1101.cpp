//本题没有AC,我也不知道为什么
#include<iostream>

using namespace std;

int n;
char g[103][103];
bool f[103][103];
string s1="yizhong";
string s2="gnohziy";

bool check(string s)
{
	return (s==s1 || s==s2);
}

int main()
{
	cin>>n;
	ios::sync_with_stdio(false);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>g[i][j];
	//横行
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-6;j++)
		{
			string s="";
			for(int k=j;k<j+7;k++)
				s+=g[i][k];
			if(check(s))
				for(int k=j;k<j+7;k++)
					f[i][k]=true;
		}
	//竖行
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-6;j++)
		{
			string s="";
			for(int k=j;k<j+7;k++)
				s+=g[k][i];
			if(check(s))
				for(int k=j;k<j+7;k++)
					f[k][i]=true;
		}
	//斜向
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-6;j++)
		{
			string s="";
			for(int k=0;k<=6;k++)
				s=s+g[j+k][i+k];
			if(check(s))
				for(int k=0;k<=6;k++)
					f[j+k][i+k]=true;
		}
		for(int j=n;j>=6;j--)
		{
			string s="";
			for(int k=0;k<=6;k++)
				s=s+g[j-k][i+k];
			if(check(s))
				for(int k=0;k<=6;k++)
					f[j-k][i+k]=true;
		}
	}
	//输出
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(f[i][j])
				cout<<g[i][j];
			else
				cout<<"*";
		}
		if(i!=n)
			cout<<"\n";
	}
	return 0;
}
