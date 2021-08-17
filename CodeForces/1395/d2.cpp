#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,d,m;
int a[100003];
long long res;
long long sum[2][100003];
vector<int> b[2];

int main()
{
    scanf("%d%d%d",&n,&d,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        b[a[i]>m].emplace_back(a[i]);
    }
    sort(b[0].begin(), b[0].end());
    reverse(b[0].begin(), b[0].end());
    sum[0][0]=0;
    for (signed int i=0; i<(int)b[0].size(); i++)sum[0][i+1]=sum[0][i]+b[0][i];
    sort(b[1].begin(), b[1].end());
    reverse(b[1].begin(), b[1].end());
    sum[1][0]=0;
    for (int i=0; i<(int)b[1].size(); i++)sum[1][i+1]=sum[1][i]+b[1][i];
    res = sum[0][b[0].size()];
    for (int i = 0;i<(int)b[1].size();i++)
    {
        if (i*(d+1)+1 > n) break;
        int rest = min((int)b[0].size(), n-i*(d+1)-1);
        res = max(res, sum[1][i+1]+sum[0][rest]);
    }
    printf("%lld\n",res);
    return 0;
}

