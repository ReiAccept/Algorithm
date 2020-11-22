#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct st
{
    char s;
    int t;
}a[31000],b[31000];

char q[31000];
int last[31000],x;

bool cmp(const st &a,const st &b)
{
    return a.s<b.s||a.s==b.s&&a.t<b.t;
}

int main()
{
    freopen("hidden.in","r",stdin);
    freopen("hidden.out","w",stdout);
    scanf("%s",q+1);
    for(int i=1; i<=strlen(q+1); i++)
    {
        a[i].s=q[i];
        a[i].t=i;
        b[i].t=i;
        b[i].s=a[i].s;
    }
    sort(a+1,a+1+strlen(q+1),cmp);
    for(int i=1; i<=strlen(q+1); i++)
    {

        last[b[i].t]=a[i].t;
        if(b[i].s=='.')
            x=b[i].t;
    }
    int w=last[x];
    while(x!=w)
    {
        printf("%c",b[w].s);
        w=last[w];
    }
    printf(".");
    return 0;
}
