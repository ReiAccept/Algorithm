#include <cstdio>

using namespace std;
int x=0;
int a[1000];
void change(int n)
{
    if(n!=0)
    {
        a[x++]=n%8;
        n=n/8;
        change(n);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    change(n);
    for(int i=x-1; i>=0; i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
