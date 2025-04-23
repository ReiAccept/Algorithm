#include <stdio.h>
#include <string.h>

#define Maxn 105

char pic[Maxn][Maxn];
int m,n,idx[Maxn][Maxn];

void dfs(int r,int c,int id);

int main()
{
    while(scanf("%d%d",&m,&n)==2 && m && n)
    {
        for(int i=0;i<m;i++)
            scanf("%s",pic[i]);
        int cnt=0;
        memset(idx,0,sizeof(idx));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(idx[i][j]==0 || pic[i][j]=='@')
                    dfs(i,j,++cnt);
        printf("%d",cnt);
    }
    return 0;
}

void dfs(int r,int c,int id)
{
    if(r<0 || c<0 || r>=m || c>=n || idx[r][c]>0 || pic[r][c]!='@')
        return;
    idx[r][c]=id;
    for(int dr=-1;dr<=1;dr++)
        for(int dc=-1;dc<=1;dc++)
            if(dr!=0 || dc!=0)
                dfs(r+dr,c+dc,id);
}