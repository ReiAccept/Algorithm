#include<iostream>

using namespace std;

const int INF=0x3f3f3f;
int n,a[100003],f[100003],c[100003],maxn=1;

int upper_bound(int l,int r,int cur)
{
    while(l!=r)
    {
        int m=(l+r)/2;
        if(c[m]<=cur) l=m+1;
        else r=m;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=INF;
    }
    f[1]=1;//f[i]为当前位置上的LIS长度
    c[1]=a[1];//c数组的下标是LIS的长度,c数组表示LIS长度为i的最小数值
    for(int i=2;i<=n;i++)
    {
        f[i]=upper_bound(1,i,a[i]);//在c数组中进行二分搜索，搜索目标为大小为a[i]的数。
        if(f[i]>maxn) maxn=f[i];
        if(c[f[i]]>a[i]) c[f[i]]=a[i];//如果当前的数值是LIS长度=i的最小值c[i]=当前数值
    }
    cout<<maxn<<endl;
    return 0;
}
/*
LIS算是真·入门题了
然而我太菜了,以前只会N方算法
NlogN算法上是加了一个c数组，c数组的下标用于记录LIS的长度，c数组的值c[i]则用于表示当前LIS长度为i时数组中的最小数值。f数组的用途不变，用于表示当前位置上的LIS长度。在c数组上对a[i]进行搜索，朝朝大小为a[i]的数，因为c数组的下标是LIS的长度，长度越长的LIS其末端数值大于前方，所以c数组可以看成一个递增数列。
*/
