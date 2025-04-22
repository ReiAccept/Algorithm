#include<cstdio>
#include<iostream>

using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int c,sum;
        scanf("%d%d",&c,&sum);
        int r=sum/c;
        int yu=sum%c;
        int ans=(yu*(r+1)*(r+1)) + (c-yu)*r*r;
        printf("%d\n",ans);
    }
    return 0;
}
