#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

struct data
{
    int x,y,dir,turn;
    bool operator < (const data &c) const
    {
        return c.turn<turn;
    }
};

priority_queue<data> q;
data temp,temp2;
int tempx,tempy,tempdir,tempturn,m,n,sum,x1,x2,yy1,y2;
int map[1010][1010];
int direct[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
bool already[1010][1010];

bool judge()
{
    if (map[tempx][tempy]!=0) return false;
    if (already[tempx][tempy]) return false;
    return true;
}

void push()
{
    temp2.x=tempx;
    temp2.y=tempy;
    temp2.dir=tempdir;
    temp2.turn=tempturn;
    q.push(temp2);
    already[tempx][tempy]=true;
}

bool bfs()
{
    if (x1<0 || x2<0 || yy1<0 || y2<0 || x1>m+1 || yy1>n+1 || x2>m+1 || y2>n+1) return false;
    if (map[x1][yy1]==0 || map[x2][y2]==0) return false;
    if (map[x1][yy1]!=map[x2][y2]) return false;
    temp.x=x1;
    temp.y=yy1;
    temp.dir=9999;
    temp.turn=-1;
    while (!q.empty()) q.pop();
    memset(already,false,sizeof(already));
    q.push(temp);
    already[x1][yy1]=true;
    while (!q.empty())
    {
        temp=q.top();
        for (int i=0; i<=3; i++)
        {
            tempx=temp.x+direct[i][0];
            tempy=temp.y+direct[i][1];
            tempdir=i;
            if (tempx<0 || tempy<0 || tempx>m+1 || tempy>n+1) continue;
            if (temp.dir==9999 || (temp.dir+i)%2==1) tempturn=temp.turn+1;
            else tempturn=temp.turn;
            if (tempturn>=3) continue;
            if (tempx==x2 && tempy==y2) return true;
            if (!judge()) continue;
            push();
        }
        q.pop();
    }
    return false;
}

double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}

void creat()
{
    int t=0,a,i,j;
    srand(time(0));
    memset(map,0,sizeof(map));
    while (t!=sum)
    {
        a=(int)random(0,26)+1;
        for (int l=1; l<=2; l++)
        {
            while (1)
            {
                i=(int)random(0,m)+1;
                j=(int)random(0,n)+1;
                if (map[i][j]==0)
                {
                    map[i][j]=a;
                    break;
                }
            }
        }
        t+=2;
    }
}

void print()
{
    char c;
    cout << "  ";
    for (int i=1; i<=n; i++)
        cout << i%10;
    cout << endl << "  ";
    for (int i=1; i<=n; i++)
        cout << "-";
    cout << endl;
    for (int i=1; i<=m; i++)
    {
        cout << i%10 << "|";
        for (int j=1; j<=n; j++)
        {
            if (map[i][j]!=0)
            {
                c=map[i][j]-1+'a';
                cout << c;
            }
            else cout << " ";
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int i=1; i<=n; i++) cout << "-";
    cout << endl;
}

void del()
{
    system("cls");
    if (bfs())
    {
        map[x1][yy1]=map[x2][y2]=0;
        sum-=2;
        if (sum!=0)
        {
            cout << "Good job!" << endl << endl;
            print();
        }
    }
    else
    {
        cout << "ERROR!" << endl << endl;
        print();
    }
}

int main()
{
    cout << "-----------------------连连看-------------------------" << endl;
    cout << "请输入两个正整数，表示地图的大小。程序将随机生成地图. " << endl;
    cout << "然后每次输入4个数，代表要消的两个格子的所在行数和列数." << endl;
    cout << "------------------------------------------------------" << endl;
    cin >> m >> n;
    cout << endl;
    sum=m*n;
    if (sum%2!=0)
    {
        cout << "ERROR" << endl;
        return 0;
    }
    creat();
    system("cls");
    cout << "Map created!" << endl << endl;
    print();
    while (1)
    {
        if (sum==0)
        {
            cout << "Congratulations!" << endl;
            break;
        }
        cin >> x1 >> yy1 >> x2 >> y2;
        cout << endl;
        del();
    }
    system("pause");
    return 0;
}
