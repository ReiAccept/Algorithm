#include<cstdio>
#include<iostream>

using namespace std;

int Case,sum;
char a[20][20];
bool v[20][20];

bool Judge(int x,int y)
{
    if(x<0||y<0||x>11||y>11)
        return false;
    if(!v[x][y]&&a[x][y]!='#')
        return true;
    else
        return false;
}
void dfs(int x,int y)
{
    v[x][y]=1;
    if(Judge(x-1,y))
        dfs(x-1,y);
    if(Judge(x+1,y))
        dfs(x+1,y);
    if(Judge(x,y-1))
        dfs(x,y-1);
    if(Judge(x,y+1))
        dfs(x,y+1);
}
int Trust_main()
{
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
            cin>>a[i][j];
    for(int i=0; i<=11; i++)
        for(int j=0; j<=11; j++)
            v[i][j]=0;
    sum=0;
    for(int i=0; i<=11; i++)
        for(int j=0; j<=11; j++)
            if(!v[i][j] && a[i][j]!='#')
            {
                dfs(i,j);
                sum++;
            }
    if(sum==1)
        return 1;
    if(sum==2)
        return 0;
    return 8;
}
int main()
{
    cin>>Case;
    while(Case--)
        cout<<Trust_main()<<endl;
    return 0;
}
