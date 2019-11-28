#include<cstdio>
#include<iostream>

using namespace std;

int T; 
short a[1000000003];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int r,b,k;
        scanf("%d%d%d",&r,&b,&k);
        for(int i=0;i*r<=1e9;i++) a[i*r]=1;
        for(int i=0;i*b<=1e9;i++)
        {
            if(!a[i*b]) a[i*b]=2;
            else a[i*b]=3;
        }
        for(int i=0;i<=1e9;i++)
        {
            int num=1;
            int flag=a[1];
            if(a[i]==flag) num++;
            else if(flag==3)
            {
                num=1;flag=a[i+1];i++;
            }
            else 
            {
                num=1;flag=a[i];
            }
            if(num>=k)
            {
                printf("REBEL\n");
                break;
            }
            if(i==1e9) printf("OBEY\n");
        }
    }
    return 0;
}
