#include<iostream>

using namespace std;

int n,ans;
char g[103][103];

bool not_yz(char a)
{
    if(a=='y'||a=='i'||a=='z'||a=='h'||a=='o'||a=='n'||a=='g')return false;
    return true;
}

void findx(int x,int y)
{
    if(g[x+1][y+1]=='i'&&g[x+2][y+2]=='z'&&g[x+3][y+3]=='h'&&g[x+4][y+4]=='o'&&g[x+5][y+5]=='n'&&g[x+6][y+6]=='g') ans++;
    if(g[x-1][y-1]=='i'&&g[x-2][y-2]=='z'&&g[x-3][y-3]=='h'&&g[x-4][y-4]=='o'&&g[x-5][y-5]=='n'&&g[x-6][y-6]=='g') ans++;
    if(g[x-1][y+1]=='i'&&g[x-2][y+2]=='z'&&g[x-3][y+3]=='h'&&g[x-4][y+4]=='o'&&g[x-5][y+5]=='n'&&g[x-6][y+6]=='g') ans++;
    if(g[x+1][y-1]=='i'&&g[x+2][y-2]=='z'&&g[x+3][y-3]=='h'&&g[x+4][y-4]=='o'&&g[x+5][y-5]=='n'&&g[x+6][y-6]=='g') ans++;

    if(g[x][y+1]=='i'&&g[x][y+2]=='z'&&g[x][y+3]=='h'&&g[x][y+4]=='o'&&g[x][y+5]=='n'&&g[x][y+6]=='g') ans++;
    
    if(g[x+1][y]=='i'&&g[x+2][y]=='z'&&g[x+3][y]=='h'&&g[x+4][y]=='o'&&g[x+5][y]=='n'&&g[x+6][y]=='g') ans++;
}

int main()
{
	cin>>n;
	ios::sync_with_stdio(false);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
            cin>>g[i][j];
            if(not_yz(g[i][j])) g[i][j]='*';
        }
    for(int i=1;i<=n;j++)
        for(int j=1;j<=n;j++)
            if(g[i][j]=='y')findx(i,j);
	return 0;
}
