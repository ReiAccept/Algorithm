#include<cstdio>

using namespace std;

char tmp;
int f[2503][3];
int w1,l1,w2,l2,n_21;

int main()
{
	while(scanf("%c",&tmp) && tmp!='E')
	{
		if(tmp=='W')
		{
			w1++;
			w2++;
		}
		if(tmp=='L')
		{
			l1++;
			l2++;
		}
		if((w1>=11 && (w1-l1)>=2) || (l1>=11 && (l1-w1)>=2))
		{
			printf("%d:%d\n",w1,l1);
			w1=l1=0;
		}
		if((w2>=21 && (w2-l2)>=2) || (l2>=21 && (l2-w2)>=2))
		{
			f[n_21][1]=w2;
			f[n_21][2]=l2;
			w2=l2=0;
			n_21++;
		}
	}
	printf("%d:%d\n\n",w1,l1);
	for(int i=0;i<n_21;i++)
		printf("%d:%d\n",f[i][1],f[i][2]);
	printf("%d:%d\n",w2,l2);
	return 0;
}
