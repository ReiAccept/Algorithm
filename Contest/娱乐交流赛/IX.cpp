#include<stdio.h>
int main(void)
{
    int sum;
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int k=0;
        int leng=0;
        if(a>b)//输入的数字可能一大一小顺序不要错了
        {
            int t;
            t=a;
            a=b;
            b=t;
            k=1;
        }
        for(int i=a;i<=b;i++)
        {
            sum=0;
            int ii=i;
            while(ii-1)
            {
                if(ii%2) ii=ii*3+1;
                else ii/=2;
                sum++;
            }
            if(sum>=leng)
            leng=sum;
        }
        if(k)
        {
            printf("%d %d %d\n",b,a,leng+1);//注意a与b交换位置的问题 没发现这个问题错了好多次
        }
        else
        printf("%d %d %d\n",a,b,leng+1);
    }
    return 0;
}
