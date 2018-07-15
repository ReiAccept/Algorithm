#include <cstdio>

using namespace std;
 
int num=1,maxt,m;

int main()
{
    scanf("%d",&maxt);
    while(scanf("%d",&m)==1)
	{
        if(m>maxt)
			maxt=m;
        num++;
    }
    printf("%d %d\n",num,maxt);
    return 0;
}
