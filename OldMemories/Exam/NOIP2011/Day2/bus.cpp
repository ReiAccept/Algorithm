//先把不用加速器的用时计算出来,一个一个计算用一个加速器能让总时间减短多少
#include <iostream>
#include<cstdio>

using namespace std;

int n,m,k,ans=0;
int Chengke_To_i_Last[10001],BusTo_i[10001],CheZhan_i_YingXiang[10001],ZongHe[10001],d[10001],ChengKeDaoDa[10001],QiDian[10001],ZhongDian[10001];

int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1; i<n; i++)
        cin>>d[i];
    for(int i=1; i<=m; i++)
    {
        cin>>ChengKeDaoDa[i]>>QiDian[i]>>ZhongDian[i];
        Chengke_To_i_Last[QiDian[i]]=max(Chengke_To_i_Last[QiDian[i]],ChengKeDaoDa[i]);
        ZongHe[ZhongDian[i]]++;
    }
    for(int i=2; i<=n; i++)
        ZongHe[i]+=ZongHe[i-1];
    BusTo_i[1]=0;
    for(int i=2; i<=n; i++)
        BusTo_i[i]=max(BusTo_i[i-1],Chengke_To_i_Last[i-1])+d[i-1];
    for(int i=1; i<=m; i++)
        ans+=BusTo_i[ZhongDian[i]]-ChengKeDaoDa[i];
    cout<<ans<<endl;
}
