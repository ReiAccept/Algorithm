#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int a,n,cnt;
int b[100000];

int main()
{
	while(cin>>n)
	{
		memset(b,0,sizeof(b));
		cnt=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			int j;
			for(j=0;j<=cnt;j++)
				if(b[j]>=a)
				{
					b[j]=a;
					break;
				}
			if(j>cnt) b[++cnt]=a;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
