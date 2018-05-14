#include<cstdio>

int Case,n,m,i,h,t,f[1<<20],q[2222222],x,y;
char s[100];

inline void ext(int x,int y)
{
    if(f[x]<0)
        f[q[++t]=x]=y;
}

int main()
{
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<1<<m; i++)
            f[i]=-1;
        while(n--)
        {
            scanf("%s",s);
            int t=0;
            for(i=0; i<m; i++)
                t=t*2+s[i]-'0';
            f[t]=m;
        }
        h=1;
        t=0;
        for(i=0; i<1<<m; i++)
            if(~f[i])
                q[++t]=i;
        while(h<=t)
        {
            x=q[h++];
            y=f[x]-1;
            for(i=0; i<m; i++)
                ext(x^(1<<i),y);
        }
        printf("%d\n",f[x]);
    }
}
