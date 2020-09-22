#include<bits/stdc++.h>

using namespace std;

int n,ans,sum;
int a[2003],ans1[2003*2003/2],ans2[2003*2003/2],pos[2003];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int x,i=1;i<=n;i++)
    {
        scanf("%d",&x);
        pos[x]=i;//posx为序号
    }
    for(int i=1;i<=n;i++) a[i]=pos[a[i]];//使ai的值为posx的对应序号
    //for(int i=1;i<=n;i++) printf("%d ",a[i]);
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(a[j]!=i) j++;//向后找
        while(j!=i)//一直向前找到刚刚比他大的一个
        {
            int l=j-1;
            while(a[l]<j)l--;
            sum+=abs(j-l);
            ans++;
            ans1[ans]=l,ans2[ans]=j;
           // printf("%d %d\n",ans1[ans],ans2[ans]);
            swap(a[l],a[j]);
            j=l;
        }
    }
    printf("%d\n%d\n",sum,ans);
    for(int i=1;i<=ans;i++) printf("%d %d\n",ans2[i],ans1[i]);
    return 0;
}
