/*
�ȼ��ڽ��Ʒֽ⣬f[i][j]��ʾ�ӵ͵��߿���iλ�����λ��jʱ����λ�͵���Сֵ
ע�⵽jֻ��O(log^3n)�֣��ʱ���ת�Ƽ���
ʱ�临�Ӷ�O(mlog^3n)
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