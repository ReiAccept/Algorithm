#include <iostream>

using namespace std;

int a[1005],flag[1005],n,nxt[1005];

int main()
{
    while(cin>>a[++n])
    	flag[n]=1;
    --n;
    int maxi=n;
    for(int i=n;i>=1;--i)
    {
        for(int j=i+1;j<=n;++j)
            if(a[i]<=a[j] && flag[i]<flag[j]+1)
            {
                flag[i]=flag[j]+1;
                nxt[i]=j;
            }
        if(flag[i]>=flag[maxi])
        	maxi=i;
    }
    printf("max=%d\n%d",flag[maxi],a[maxi]);
    while(nxt[maxi]!=0)
    {
        maxi=nxt[maxi];
        printf(" %d",a[maxi]);
    }
    printf("\n");
    return 0;
}
