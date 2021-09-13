#include<cstdio>
#include<cstring>

using namespace std;

int n,m,ans;
int grap[1003][1003],jnmj[1003];
bool used[1003];

bool findx(int x)//传入变量x为第x道题 
{
	for(int i=0;i<n;i++)//枚举的是锦囊妙计 
	{
		if(grap[x][i] && !used[i])//可以使用这个锦囊妙计并且这个没有被使用过 
		{
			used[i]=true;
			if(!jnmj[i] || findx(jnmj[i]))//当前妙计为0(没分配给任何题目)或递归可以找到新的分配 
			{
				jnmj[i]=x;//分配给题目 
				return true;
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		grap[i][a]=grap[i][b]=true;
	}
	for(int i=1;i<=m;i++)
	{
		memset(used,0,sizeof(used));
		if(findx(i))
			ans++;
		else
			break;
	}
	printf("%d",ans);
	return 0;
}
