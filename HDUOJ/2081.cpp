#include<cstdio>
#include<cstring>

using namespace std;

int t,i;
char s[15];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        printf("6");
        for(i=6; i<(int)strlen(s); i++) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
