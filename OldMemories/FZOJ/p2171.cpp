#include<cstdio>

using namespace std;

int h,m,s;
char qwq;

int main()
{
	scanf("%d%c%d%c%d",&h,&qwq,&m,&qwq,&s);
    for(int i=5;i>=0;i--)
        printf("%d%d%d",(h>>i)&1,(m>>i)&1,(s>>i)&1);
    printf(" ");
    for(int i=5;i>=0;i--)
        printf("%d",(h>>i)&1);
    for(int i=5;i>=0;i--)
        printf("%d",(m>>i)&1);
    for(int i=5;i>=0;i--)
        printf("%d",(s>>i)&1);
    return 0;
}
