#include<cstring>
#include<iostream>

using namespace std;

int T,n;
int bad[53];
bool vis[53],badcan[53][53],stu[53],stux[53];

bool findx(int x)
{
    for(int i=1;i<=n;i++)
        if(!vis[i] && badcan[x][i] && stu[i])
        {
            vis[i]=true;
            if(!bad[i] || findx(bad[i]))
            {
                bad[i]=x;
                return true;
            }
        }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        memset(bad,0,sizeof(bad));
        memset(badcan,0,sizeof(badcan));
        memset(stu,0,sizeof(stu));
        memset(stux,0,sizeof(stux));
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>stu[i];
        for(int i=1;i<=n;i++)
        {
            int tmp;
            cin>>tmp;
            if(stu[i])stux[i]=tmp;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cin>>badcan[i][j];
            if(stu[i])
                badcan[i][i]=true;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if((!stux[i]) && (!findx(i)))//其实不知道为何前面要匹配不回家的学生
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"^_^"<<endl;
        else
            cout<<"T_T"<<endl;
    }
    return 0;
}
