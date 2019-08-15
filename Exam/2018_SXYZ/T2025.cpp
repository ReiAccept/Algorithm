#include<cstdio>
#include<algorithm>

using namespace std;

struct point
{
    int x,y,z;
}a[50003];

int n;

bool sort(point a,point b)
{
    return a.z<b.z;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    return 0;
}
