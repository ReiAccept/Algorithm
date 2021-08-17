#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3+3;
int cnt,n,m;
char a[maxn][maxn] ,b[maxn][maxn];
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)scanf("%s",a+i);
	for(int i=0;i<n;i++)scanf("%s",b+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]!=b[i][j]) cnt++;
	if(cnt>n*m/2)
    {
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]=='.') a[i][j]='X';
				else a[i][j]='.';
	}
	for(int i=0;i<n;i++) printf("%s\n",a+i);
	return 0;
}
