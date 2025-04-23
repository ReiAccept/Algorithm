#include<cstdio>
#include<algorithm>

using namespace std;

int L,N,M,ans;
int a[50000];

int main()
{
    scanf("%d%d%d",&L,&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    int l=0,r=L;
    while(l<=r)
    {
        int m=(l+r)>>1;
        int now=0,sum=0;
        for(int i=1;i<=N;i++)
        {
            if(a[i]-a[now]<m) sum++;//如果一块石头的间距小于当前m，则搬走
            else now=i;//如果一块石头的间距大于当前m，则跳到这块石头上
        }
        if(sum<=M)
        {
            ans=m;
            l=m+1;
        }
        else r=m-1;
        //printf("%d %d\n",l,r);
    }
    printf("%d\n",ans);
    return 0;
}
