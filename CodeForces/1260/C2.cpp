#include<cstdio>
#include<iostream>

using namespace std;

int T; 

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int r,b,k;
        scanf("%d%d%d",&r,&b,&k);
        if(b>r) swap(r,b);
        if(r/b>k) printf("REBEL\n");
        else printf("OBEY\n");
    }
    return 0;
}
