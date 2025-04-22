#include<bits/stdc++.h>

using namespace std;

int n;

void work()
{
    scanf("%d",&n);
    while(n%2==0) {
        n>>=1;
    }
    while(n%5==0) {
        n/=5;
    }
    if(n==1) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
}

signed main()
{
    signed T; scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}