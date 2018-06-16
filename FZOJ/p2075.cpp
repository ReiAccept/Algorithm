#include <cstdio>
#include <algorithm>

using namespace std;

int x[4], y[4];
int tx[23],ty[23];
int maxx,maxy,maxn,maxi;

int main()
{
	for(int i=1;i<=4;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		tx[x[i]]++;
		ty[y[i]]++;
	}
	for(int i=1;i<=19;i++)
	{
		maxx=max(maxx,tx[i]);
		maxy=max(maxy,ty[i]);
	}
	if(maxx==4 || maxy==4) 
		printf("zhisi");
	else if(maxx==3 || maxy==3)
	{
		for(int i=1;i<=19;i++)
			if(maxx==3 && maxn<ty[i]) 
			{ 
				maxn=ty[i]; 
				maxi=i; 
			}
			else if(maxy==3 && maxn<tx[i]) 
			{
				maxn=ty[i]; 
				maxi=i;
			}
		if((maxx==3 && ty[maxi-1] && ty[maxi+1])||(maxy==3 && tx[maxi-1] && tx[maxi+1]))
			printf("dingsi");
		else 
			printf("qusi");
	}
	else
	{
		sort(x+1,x+1+4);
		sort(y+1,y+1+4);
		int kx=1,ky=1;
		for(int i=1;i<=4-1;i++)
		{
			if(x[i] != x[i+1])
				kx++;
			if(y[i] != y[i+1]) 
				ky++;
		}
		if(kx==ky) 
			printf("fangsi");
		else 
			printf("wansi");
	}
	return 0;
}
