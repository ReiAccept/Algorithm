#include<cstdio>

using namespace std;

int n,k,q,sum1,sum2;
int a[200003],sum[200003];

void printxx()//for debug
{
    for(int i=89;i<=103;i++) printf(" %d",sum[i]); printf("\n");
    for(int i=89;i<=103;i++) printf(" %d",a[i]); printf("\n");
}

int main()
{
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        a[l]++,a[r+1]--;//差分
    }
    for(int i=1;i<=200000;i++)
    {
        sum1+=a[i];
        if(sum1>=k) sum2++;
        sum[i]=sum2;//前缀和数组
    }
    //printxx();
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);//前缀和
    }
    return 0;
}
//wocao那么多年了我一直以为这个靠乱搞，原来这个还能叫差分==
