#include<cstdio>
#include<iostream>

using namespace std;

int n;
int a[500003],c[500003];
long long ans;

void msort(int sta,int end)
{
    if(sta==end) return;
    int mid=(sta+end)>>1,i=sta,j=mid+1,k=sta;
    msort(sta,mid);msort(mid+1,end);
    while(i<=mid && j<=end)
        if(a[i]<=a[j]) c[k++]=a[i++];
        else c[k++]=a[j++],ans+=(mid-i+1);
    while(i<=mid) c[k++]=a[i++];
    while(j<=end) c[k++]=a[j++];
    for(int cur=sta;cur<=end;cur++)a[cur]=c[cur];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    msort(1,n);
    cout<<ans<<endl;
    return 0;
}
//归并排序模板题
//如果我们想要将一个序列排成从小到大有序的，那么每次划分后合并时左右子区间都是从小到大排好序的，我们只需要统计右边区间每一个数分别会与左边区间产生多少逆序对即可。
//在某个时候，左区间：  5 6 7  下标为i
//           右区间：  1 2 9  下标为j
//这个时候我们进行合并：
//step 1：由于 5>1，所以产生了逆序对，这里，我们发现，左区间所有还没有被合并的数都比 1 大，所以1与左区间所有元素共产生了 3 个逆序对(即tot_numleft-i+1对)，统计答案并合并 1 
//step 2：由于 5>2，由上产生了3对逆序对，统计答案并合并 2
//step 3：由于 5<9, 没有逆序对产生，右区间下标 j++
//step 4：由于 6<9, 没有逆序对产生，右区间下标 j++
//step 5：由于 7<9, 没有逆序对产生，右区间下标 j++
//step 6：由于右区间已经结束，正常执行合并左区间剩余，结束

//PS： tot_numleft=3，即左区间总元素个数
