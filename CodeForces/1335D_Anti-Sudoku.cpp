#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

char ch;

void Solve()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin>>ch;
			if(ch=='1') cout<<'2';
			else cout<<ch;
		}
		cout<<endl;
	}
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
