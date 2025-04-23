#include<cstdio>

using namespace std;

int a[203],b[203];
int n,na,nb,ansa,ansb;
int df[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};

int main()
{
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<nb;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
	{
		ansa+=df[a[i%na]][b[i%nb]];
		ansb+=df[b[i%nb]][a[i%na]];
	}
	printf("%d %d",ansa,ansb);
	return 0;
}
