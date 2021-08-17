#include<cstdio>

using namespace std;

int n,maxi,maxp;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int t,r,w,b;
        scanf("%d%d%d%d",&t,&r,&w,&b);
        int p=r+w*2+b*3;
        if(p>maxp)
        {
            maxi=t;
            maxp=p;
        }
    }
    printf("%d %d",maxi,maxp);
    return 0;
}
