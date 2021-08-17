#include<cstdio>
#include<algorithm>

using namespace std;

int n,cnt,sum;
int a[100],p[100];
bool used[100];

bool cmp(int a,int b)//迷之卡常
{
	return a>b;
}

void dfs(int last,int k,int l,int len,int ts)//len->长度;
{
	if(l==len)//枚举出l长度和
	{
		l=0;
		k++;
		last=1;
	}
	if(k==ts+1)
	{
		printf("%d\n",len);
		exit(0);//在任何地方结束程序
	}
	for(int i=last;i<=cnt;i++)
		if(!used[i] && l+a[i]<=len)
		{
			if((a[i]==a[i-1] && !used[i-1]) || (l+p[i]<len))
				continue;
			used[i]=true;
			dfs(i+1,k,l+a[i],len,ts);
			used[i]=false;//回溯
			if((l==0) || (a[i]+l==len))
				return;
		}
}

int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp<=50)
		{
			a[++cnt]=tmp;//小细节要注意,由于这个卡了几次
			sum+=tmp;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=cnt;i>=1;i--)
		p[i]=p[i+1]+a[i];
	for(int i=a[1];i<=sum/2;i++)//从第一个最短的长度开始枚举当
		if(sum%i==0)//l必须要整除sum
			dfs(1,1,0,i,sum/i);
	printf("%d\n",sum);//实在是没啥好输出,输出总和
	return 0;
}

/*
MDZZZZZZZZZZZZ这题可以DP的,非要我搜索
枚举每一个长度l,DFS检查这个长度l是否合法。
1st:l如果不整除sum略过
2nd:枚举下界当i>sum/2明显不能被sum整除上界只优化了下常数类似剪枝1
3rd:将木棍从大到小排序进行枚举
4th:在凑成某根木棍时,从它上一次用的木棍编号的下一位开始枚举,因为反过来是一样的。
5th:如果某个长度和上一个长度一样且上一个长度的没有用,那么这个也不能用。
6th:维护后缀和数组p[i],如果当前长度加上最后所有能用的和还不够木棍原长,不能用。
7th:如果从当前编号枚举完整的棍子失败了以后,因为每个残棍都得用上,所以不行。
8th:如果当前长度加上枚举长度失败了以后,不用往后枚举了。因为哪怕后面有更小的能代替这个枚举长度也不可能产生更优的结果,因为更短的长度明显有更多选择
*/
