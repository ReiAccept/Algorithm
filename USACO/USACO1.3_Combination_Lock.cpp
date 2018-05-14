/*
ID: sa128471
PROG: combo
LANG: C++
*/
#include<cstdio>

using namespace std;

int n,a[3],b[3],ans=0;

bool Find(int x, int y);

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<3; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<3; i++)
        scanf("%d",&b[i]);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                if((Find(i,a[0]) && Find(j,a[1]) && Find(k,a[2]))||(Find(i,b[0]) && Find(j,b[1]) && Find(k,b[2])))
                    ans++;
    printf("%d\n",ans);
    return 0;
}

bool Find(int x, int y)
{
    int flag;
    for(int i=-2; i<=2; i++)
    {
        flag=y+i;
        if(flag<=0)
            flag+=n;
        if(flag>n)
            flag-=n;
        if(x==flag)
            return true;
    }
    return false;
}
