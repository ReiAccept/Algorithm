#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int x1,y1,x2,y2;
int s[103][103];

queue<int>q[4];

const int dx[12]={-2,-2,-1,1,2,2,2,2,1,-1,-2,-2};
const int dy[12]={-1,-2,-2,-2,-2,-1,1,2,2,2,2,1};

int main()
{
    memset(s,-1,sizeof(s));
    cin>>x1>>y1>>x2>>y2;
    q[1].push(1);
    q[2].push(1);
    q[3].push(0);
    while(!q[1].empty() && !q[2].empty() && !q[3].empty())
    {
        for(int i=0;i<12;i++)
        {
            int x=q[1].front()+dx[i];
            int y=q[2].front()+dy[i];
            if(x>0 && y>0 && x<=100 && y<=100)
                if(s[x][y]==-1)
                {
                    s[x][y]=q[3].front()+1;
                    q[1].push(x);
                    q[2].push(y);
                    q[3].push(s[x][y]);
                    if(s[x1][y1]>0 && s[x2][y2]>0)
                    {
                        cout<<s[x1][y1]<<endl;
                        cout<<s[x2][y2]<<endl;
                        return 0;
                    }
                }
        }
        q[1].pop();
        q[2].pop();
        q[3].pop();
    }
    return 0;
}
