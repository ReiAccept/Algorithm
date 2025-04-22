#include<cstdio>
#include<iostream>

using namespace std;

int w;

int main()
{
    scanf("%d",&w);
    if(w==2) printf("NO\n");
    else if(w%2==0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
