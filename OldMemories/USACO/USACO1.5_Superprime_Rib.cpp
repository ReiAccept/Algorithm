#include<cstdio>

using namespace std;

int n,sum;

bool cheak(int x)
{	
	if(x==1)
		return false;
    for(int i=2;i*i<=x;i++)
        if(x % i==0)
			return false;
    return true;
}

void dfs(int x)
{
    for(int i=1;i<=9;i++)
	{
        sum=sum*10+i;
        if(cheak(sum))
            if(x==n)
                printf("%d\n",sum);
            else
                dfs(x+1);
		sum=sum/10;
	}
}

int main()
{
    scanf("%d",&n);
  	dfs(1);
	return 0;
}
