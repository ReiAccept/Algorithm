#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int x,y,z;
}a[50003];

int n;
double ans;

bool cmp(Node a,Node b)
{
    return a.z<b.z;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+1+n,cmp);
    for(int i=2;i<=n;i++)
        ans+=(sqrt((a[i].x-a[i-1].x)*(a[i].x-a[i-1].x)+(a[i].y-a[i-1].y)*(a[i].y-a[i-1].y)+(a[i].z-a[i-1].z)*(a[i].z-a[i-1].z)));
    printf("%.3lf\n",ans);
    return 0;
}
