#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[1003];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=n;i++)
        while(a[i]--)printf("%d ",i);
    return 0;
}
