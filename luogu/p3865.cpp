#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
int Max[1000005][21];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>Max[i][0];
    for(int j=1;j<=21;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
    {
        int l,r;cin>>l>>r;
        int k=log2(r-l+1);
        cout<<max(Max[l][k],Max[r-(1<<k)+1][k])<<endl;
    }
    return 0;
}
//ST表模板题
//MDZZ洛谷,模板题卡常数,非要加一个快读
