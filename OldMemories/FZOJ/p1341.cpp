#include<cstdio>

int N;
const int HC[10]= {6,2,5,5,4,5,6,3,7,6};
int Result=0;

int genshu(int num)
{
    if(0==num)
    {
        return HC[0];
    }
    else
    {
        int sum=0;
        while(1)
        {
            if(num<=0)
            {
                break;
            }
            else
            {
                sum+=HC[num%10];
                num=num/10;
            }
        }
        return sum;
    }
}

int main()
{
    scanf("%d",&N);
    int i,j;
    int num1,num2,num3;
    for(i=0; i<=1111; i++)
    {
        num1=genshu(i);
        if(num1<N-4)
        {
            for(j=0; j<=1111-i; j++)
            {
                num2=genshu(j);
                num3=genshu(i+j);
                if(num1+num2+num3==N-4)
                {
                    Result++;
                }
            }
        }
    }
    printf("%d\n",Result);
}
