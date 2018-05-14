#include<cstdio>

int Case,n,k,h,t,f[1<<20],q[2222222],x,y;
char s[100];

inline void ext(int x,int y)
{
    if(f[x]<0)
        f[q[++t]=x]=y;
}

void Trust_main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<1<<k; i++)//2的k次方
        f[i]=-1;
    while(n--)
    {
        scanf("%s",s);
        int t=0;
        for(int i=0; i<k; i++)
            t=t*2+s[i]-'0';//s[i]-'0'最后结果是1的得1,是0的得0
        f[t]=k;
    }
    h=1;
    t=0;
    for(int i=0; i<1<<k; i++)
        if(~f[i])//对f[i]取反,只有在-1的时候
            q[++t]=i;
    while(h<=t)
    {
        x=q[h++];
        y=f[x]-1;
        for(int i=0; i<k; i++)
            ext(x^(1<<i),y);
    }
    printf("%d\n",f[x]);
}

int main()
{
    scanf("%d",&Case);
    while(Case--)
        Trust_main();
    return 0;
}
