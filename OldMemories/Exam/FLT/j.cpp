#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

bool visit[35][35][35];
char map[35][35][35];
int l,r,c;

struct node{
    int x,y,z,s;
};

queue<node> q;

inline void addnode(node m2)
{
    if(!visit[m2.x][m2.y][m2.z] && map[m2.x][m2.y][m2.z]!='#') visit[m2.x][m2.y][m2.z]=true,q.push(m2);
}

int main()
{
    while(cin>>l>>r>>c && (l||r||c))
    {
        while(!q.empty()) q.pop();
        memset(visit,false,sizeof(visit));
        memset(map,'.',sizeof(map));
        bool flag=false;
        node start;
        for(int i=0; i<l; i++)for(int j=0; j<r; j++)for(int k=0; k<c; k++)if(cin>>map[i][j][k] && map[i][j][k]=='S') start.x=i,start.y=j,start.z=k,start.s=0;
        q.push(start);
        visit[start.x][start.y][start.z]=true;
        while(!q.empty())
        {
            node m=q.front();
            q.pop();
            if(map[m.x][m.y][m.z]=='E')
            {
                printf("Escaped in %d minute(s).\n",m.s);
                flag=true;
                break;
            }
            m.s++;
            node m2;
            if(m.x-1>=0)
            {
                m2=m;
                m2.x--;
                addnode(m2);
            }
            if(m.x+1<l)
            {
                m2=m;
                m2.x++;
                addnode(m2);
            }
            if(m.y-1>=0)
            {
                m2=m;
                m2.y--;
                addnode(m2);
            }
            if(m.y+1<r)
            {
                m2=m;
                m2.y++;
                addnode(m2);
            }
            if(m.z-1>=0)
            {
                m2=m;
                m2.z--;
                addnode(m2);
            }
            if(m.z+1<c)
            {
                m2=m;
                m2.z++;
                addnode(m2);
            }
        }
        if(!flag) puts("Trapped!");
    }
    return 0;
}
