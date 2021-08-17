#include<bits/stdc++.h>

using namespace std;

int n,sum,half,q;
int t[100003];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);
        sum+=t[i];
    }
    for(int i=1;i<=n;i++)
    {
        q+=t[i];
        half++;
        if(q>(sum>>1)) break;
    }
    if(sum-q>=q-t[half])printf("%d %d\n",half,n-half);
    else printf("%d %d\n",half-1,n-half+1);
    return 0;
}
