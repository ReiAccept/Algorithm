#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int n,d,m;
int a[100003];
long long sum[2][100003];
vector<int> b[2];

signed main()
{
    scanf("%d%d%d",&n,&d,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        b[a[i]>m].emplace_back(a[i]);
    }
    for(int k=0;k<2;k++)
    {
        sort(b[k].begin(), b[k].end());
        reverse(b[k].begin(), b[k].end());
        sum[k][0]=0;
        for(int i=0;i<(int)b[k].size();i++)sum[k][i+1]=sum[k][i]+b[k][i];
    }
    long long res = sum[0][b[0].size()];
    for(int i = 0; i < (int)b[1].size(); ++i)
    {
        if (i*(d+1)+1 > n) break;
        int rest = min((int)b[0].size(), n-i*(d+1)-1);
        res = max(res, sum[1][i+1]+sum[0][rest]);
    }
    cout << res << endl;
    return 0;
}

