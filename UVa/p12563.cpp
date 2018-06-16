#include<cstdio>
#include<algorithm>

using namespace std;

const int JGJQ=678;
int a[50+20],f[50*3*60+1];//50首,每首<=3min,每分钟60s,+1s(滑稽

int main()
{
    int T;
    scanf("%d",&T);
    for(int l=1;l<=T;l++)//要输出组数,不要T--
    {
		int n,t,sum=0;
        scanf("%d%d",&n,&t);
        for(int i=1;i<=n;i++)
        {
			scanf("%d",&a[i]);
			sum+=a[i];
        }
        if(t>sum)//t大于所有歌的长度,直接输出歌数+1时间加上劲歌金曲
        {
            printf("Case %d: %d %d\n",l,n+1,sum+JGJQ);
            continue;
        }
        f[0]=0,t=t-1;//留1s给劲歌金曲
        for(int i=1;i<=t;i++)
			f[i]=-1;//初始化01背包,同时去掉劲歌金曲这首歌
        
        for(int i=1;i<=n;i++)//01背包计算最多能唱的歌曲数
            for(int j=t;j>=a[i];j--)
                f[j]=max(f[j],f[j-a[i]]+1);
        
        int ma=-1;//求最长能唱的时间,ma表示能唱的歌数(不含劲歌金曲)
        for(int i=t;i>=0;i--)
            if(f[i]>ma)
            {
				ma=f[i];
				sum=i;
            }
        printf("Case %d: %d %d\n",l,ma+1,sum+JGJQ);
    }
    return 0;
}
