/*
等价于进制分解，f[i][j]表示从低到高考虑i位，最高位是j时，低位和的最小值
注意到j只有O(log^3n)种，故暴力转移即可
时间复杂度O(mlog^3n)
*/
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,ans;int Case,m,i,j,k;map<ll,int>f[110];map<ll,int>::iterator o;
int main(){
  scanf("%d",&Case);
  while(Case--){
    ans=~0ULL>>1;
    for(i=0;i<110;i++)f[i].clear();
    scanf("%lld%d",&n,&m);
    f[1][n]=0;
    for(i=1;i<m;i++)for(o=f[i].begin();o!=f[i].end();o++)for(j=2;j<6;j++){
      n=o->first/j,k=o->second+o->first%j;
      if(f[i+1].find(n)==f[i+1].end())f[i+1][n]=k;else f[i+1][n]=min(f[i+1][n],k);
    }
    for(o=f[i].begin();o!=f[i].end();o++)ans=min(ans,o->first+o->second);
    printf("%lld\n",ans);
  }
}