/*
ID: sa128471
PROG: crypt1
LANG: C++
*/
#include<cstdio>

using namespace std;

int n,flag;
int num[11];
bool r[10005];

void check();
bool fd(int x);

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    check();
    for(int i=11;i<=99;i++)
    {
        if(!r[i])
            continue;
        for(int j=111;j<=999;j++)
        {
            if(i*j>9999 || i*j<1000 || (i%10)*j>999 || (i/10)*j>999)
                break;
            if(r[j] && r[i*j] && r[(i%10)*j] && r[(i/10)*j])
                flag++;
        }
    }
    printf("%d\n",flag);
    return 0;
}

void check()
{
    for(int i=11;i<=9999;i++)
    {
        if(i>=11 && i<=99)
        {
            if(fd(i%10) && fd(i/10))
                r[i]=true;
        }
        else if(i>=111 && i<=999)
        {
            if(fd(i%10) && fd((i/10)%10) && fd(i/100))
                r[i]=true;
        }
        else if(i>=1111 && i<=9999)
        {
            if(fd(i%10) && fd((i/10)%10) && fd((i/100)%10) && fd(i/1000))
                r[i]=true;
        }
    }
}

bool fd(int x)
{
    if(x==0)
        return false;
    for(int i=0;i<n;i++)
        if(x==num[i])
            return true;
    return false;
}
