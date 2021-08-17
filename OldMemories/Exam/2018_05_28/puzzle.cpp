#include <cstdio>
#include <iostream>

using namespace std;

int n;
bool alldot=true;
bool g[110][110];

inline bool checkx(int x, int y)//其实这里可以选择void然后直接出NOreturn0
{
    return 1 <= x && x <= n && 1 <= y && y <= n && g[x][y]; 
}

inline bool check(int i,int j)
{
	return (checkx(i+1,j) && checkx(i+1,j-1) && checkx(i+1,j+1) && checkx(i+2,j));
}

int main()
{
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            char c;
            cin>>c; //我讨厌这样的输入,辣鸡玩意,scanf工作不正常,非要我加个iostream
            if (c=='#') 
				g[i][j]=true,alldot=false;
        }
	if(alldot)
	{
		printf("YES");
		return 0;
	}
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (g[i][j])
            {
                if (check(i,j))//这里写屎了,其实可以合并到check
                {
                    g[i][j] = false;
                    g[i+1][j] = false;
                    g[i+1][j-1] = false;
                    g[i+1][j+1] = false;
                    g[i+2][j] = false;
                }
                else
                {
                    printf("NO");
			        return 0;
                }
            }
	printf("YES");
	return 0;
}
