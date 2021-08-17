#include <cstdio>

using namespace std;

int map[105][105], opt[105];
bool flag[105];

int main() 
{
	int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				scanf("%d", &map[i][j]);
    int i, ver, num = n - 1, minn, sum = 0;
	flag[1] = true;
	for(i = 1; i <= n; i ++)
		opt[i] = map[1][i];
	while(num --)
{
		minn = 2147483647;
		for(i = 1; i <= n; i ++)
{
			if(!flag[i] && opt[i] < minn)
{
				ver = i;
				minn = opt[i];
			}
		}
		flag[ver] = true;
		sum += minn;
		for(i = 1; i <= n; i ++)
			if(!flag[i] && opt[i] > map[ver][i])
				opt[i] = map[ver][i];
	}
	printf("%d",sum);
	return 0;
}
