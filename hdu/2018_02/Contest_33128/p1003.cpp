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
    for(int i=0; i<1<<k; i++)//2��k�η�
        f[i]=-1;
    while(n--)
    {
        scanf("%s",s);
        int t=0;
        for(int i=0; i<k; i++)
            t=t*2+s[i]-'0';//s[i]-'0'�������1�ĵ�1,��0�ĵ�0
        f[t]=k;
    }
    h=1;
    t=0;
    for(int i=0; i<1<<k; i++)
        if(~f[i])//��f[i]ȡ��,ֻ����-1��ʱ��
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
