#include<bits/stdc++.h>

using namespace std;

int n;
int a[1003]= {1000},powx[]={1,10,100,1000};

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",a+i);
    for(int i=1; i<=n; i++)
    {
        if(a[i]==a[i-1]) continue;
        if(a[i]>a[i-1])
        {
            for(int j=3; j>=0; j--)
            {
                for(int k=(a[i]/powx[j])%10; k>=1; k--)
                {
                    if(a[i]-k*powx[j]>=a[i-1])
                    {
                        a[i]-=(k*powx[j]);
                        goto fuck;
                    }
                }
            }
        }
        else if(a[i]<a[i-1])
        {
            for(int j=0; j<=3; j++)
            {
                for(int k=1;9-((a[i]/powx[j])%10)-k>=0; k++)
                {
                    //printf("X%d\n",a[i]+k*powx[j]);
                    if(a[i]+k*powx[j]>=a[i-1])
                    {
                        a[i]+=(k*powx[j]);
                        goto fuck;
                    }
                }
            }
        }
fuck:
        if(a[i]<a[i-1] || a[i]>2011)
        {
            printf("No solution\n");
            return 0;
        }
    }
    for(int i=1; i<=n; i++) printf("%d\n",a[i]);
    return 0;
}
