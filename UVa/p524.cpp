#include<cstdio>
#include<cstring>
#include<iostream>

int n,ansx;
int a[20];
bool vis[20];
bool notprime[37];

void dfs(int s)
{
	if(s==n && !notprime[a[1]+a[n]])
	{
		for(int i=1;i<n;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	else
		for(int i=2;i<=n;i++)
			if(!vis[i] && !notprime[i+a[s]])
			{
				a[s+1]=i;
				vis[i]=true;
				dfs(s+1);
				vis[i]=false;
			}
}

int main()
{
	for(int i=2;i<=36;i++)
		for(int j=2;i*j<=36;j++)
			notprime[i*j]=true;
	notprime[1]=notprime[2]=true;
	while(std::cin>>n)
	{
		memset(vis,0,sizeof(vis));
		a[1]=1;
		if(ansx)
			printf("\n");
		printf("Case %d:\n",++ansx);
		dfs(1);
	}
	return 0;
}

/*以下是AC代码
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int a[20],vis[20];

int isp(int n)           //判断是否为素数
{
    if(n<2)
        return false;
    for(int i=2;i*i<=n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

void dfs(int s)
{
    if(s==n&&isp(a[1]+a[n]))  //递归边界。别忘了测试第一个数和最后一个数
    {
        for(int i=1; i<n; i++)
            cout<<a[i]<<" ";
        cout<<a[n]<<endl;
    }
    else
    {
        for(int i=2; i<=n; i++)
        {
            if(!vis[i]&&isp(i+a[s]))   //如果i没有用过，并且与钱一个数之和为素数
            {
                a[s+1]=i;
                vis[i]=1;              //标记
                dfs(s+1);
                vis[i]=0;              //清除标记
            }
        }
    }
}
int main()
{
    int t=0;
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        a[1]=1;
        if(t!=0) cout<<endl;            //一定注意输出格式
        t++;
        cout<<"Case "<<t<<":"<<endl;
        dfs(1);
    }
    return 0;
}
*/
