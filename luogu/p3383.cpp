#include<cstdio>
#include<cmath>

using namespace std;

int n,m,fw,tmp;
bool a[100000000];

int main()
{
	scanf("%d%d",&n,&m);
    fw=sqrt(n+0.5);
    a[1]=1;
    for(int i=2;i<=fw;i++)
    {
        if(a[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
                a[j]=1;    
        }
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&tmp);
        if(a[tmp]==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
