#include<cstdio>
#include <cstring>

int x1[1000];
int y1[1000];
char s[60][60];
int f[60][60];
int a[60][60];
int ff[10];
int flag;
int n,m,len,ans;


void check(int x,int y)
{
    flag=0;
    int t=0;
    if (a[x1[len]-1+x][y1[len]+y]) t=1;
    else
        for(int i=0; i<len; i++)
            if (s[x1[i]-1+x][y1[i]+y]=='#')
            {
                t=1;
                break;
            }
    if (!t) ff[flag++]=1;
    t=0;
    if (a[x1[len]+1+x][y1[len]+y]) t=1;
    else
        for(int i=0; i<len; i++)
            if (s[x1[i]+x+1][y1[i]+y]=='#')
            {
                t=1;
                break;
            }
    if (!t) ff[flag++]=2;
    t=0;
    if (a[x1[len]+x][y1[len]+y+1]) t=1;
    else
        for(int i=0; i<len; i++)
            if (s[x1[i]+x][y1[i]+y+1]=='#')
            {
                t=1;
                break;
            }
    if (!t) ff[flag++]=3;
    t=0;
    if (a[x1[len]+x][y1[len]+y-1]) t=1;
    else
        for(int i=0; i<len; i++)
            if (s[x1[i]+x][y1[i]-1+y]=='#')
            {
                t=1;
                break;
            }
    if (!t) ff[flag++]=4;
}
void Findx(int x,int y)
{
    a[x1[len]+x][y1[len]+y]=1;
    check(x,y);
    int fl=flag;
    int fa[10];
    for(int i=0; i<fl; i++) fa[i]=ff[i];
    for(int i=0; i<fl; i++)
    {
        if (fa[i]==1)
        {
            for(int j=0; j<=len; j++)
                ans+=f[x1[j]+x-1][y1[j]+y],f[x1[j]+x-1][y1[j]+y]=0;
            Findx(x-1,y);
        }
        if (fa[i]==2)
        {
            for(int j=0; j<=len; j++)
                ans+=f[x1[j]+x+1][y1[j]+y],f[x1[j]+x+1][y1[j]+y]=0;
            Findx(x+1,y);
        }
        if (fa[i]==3)
        {
            for(int j=0; j<=len; j++)
                ans+=f[x1[j]+x][y1[j]+y+1],f[x1[j]+x][y1[j]+y+1]=0;
            Findx(x,y+1);
        }
        if (fa[i]==4)
        {
            for(int j=0; j<=len; j++)
                ans+=f[x1[j]+x][y1[j]+y-1],f[x1[j]+x][y1[j]+y-1]=0;
            Findx(x,y-1);
        }
    }
}

int main()
{
    int pp;
    scanf("%d",&pp);
    for(int p=1; p<=pp; p++)
    {
        len=0;
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            getchar();
            for(int j=1; j<=m; j++)
            {
                scanf("%c",&s[i][j]);
                if (s[i][j]=='.')
                    f[i][j]=1;
                if (s[i][j]=='o')
                {
                    s[i][j]='.';
                    x1[len]=i;
                    y1[len]=j;
                    len++;
                }
                if (s[i][j]=='#') a[i][j]=1;
            }
        }
        for(int i=0; i<n+2; i++)
            s[i][0]='#',s[i][m+1]='#',a[i][0]=1,a[i][m+1]=1;
        for(int i=0; i<m+2; i++)
            s[0][i]='#',s[n+1][i]='#',a[0][i]=1,a[n+1][i]=1;
        ans=len;
        len--;
        Findx(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
