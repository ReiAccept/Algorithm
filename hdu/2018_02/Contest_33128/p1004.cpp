#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int ta,tb,n,i;
long long ans;
long long a[1<<21],b[1<<21], w[50], m;

void dfs(int x, int n, long long now, long long *a, int &ta)
{
    if(now > m)
        return;
    if(x > n)
    {
        a[++ta] = now;
        return;
    }
    dfs(x + 1, n, now, a, ta);
    dfs(x + 1, n, now + w[x], a, ta);
}
void qwq()
{
    ta=tb=0;
    ans=0;
    cin>>n>>m;
    for(i = 1 ; i <= n ; i ++ )
        cin>>w[i];
    dfs(1, n/2, 0, a, ta);
    dfs((n/2) + 1, n, 0, b, tb);
    sort(a + 1, a + ta + 1);
    for(i = 1 ; i <= tb ; i ++ )
    {
        if(m - b[i] >= a[ta])
            ans += ta;
        else
            ans += upper_bound(a + 1, a + ta + 1, m - b[i]) - a - 1;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int nx;
    cin>>nx;
    for(int i=1; i<=nx; i++)
        qwq();
    return 0;
}

/*
看数据范围会T，考虑把序列分成左右两部分，
对于每部分求出它所有可以消耗钱数的方案。然后考虑左右组合怎么能够使总钱数不超过m。
考虑枚举右边序列的某钱数，那么左边的钱数要求就是不超过m-右边钱数。
所以可以对左边序列排序，然后再二分查找即可知道不超过m-右边钱数的数的个数。把这个个数累加到答案中即可。
*/
