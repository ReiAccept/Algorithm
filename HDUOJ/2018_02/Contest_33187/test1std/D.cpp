#include<cstdio>
int Case,n,i,k,x,l,r,mid,ans,sum[200010];
int check(int x){
  for(int i=1,j,l,r,t,mid,now,flag;i<=n;i++){
    for(t=i-1,now=k,flag=1;now>1;now--){
      j=t,l=j+1,r=i+n-now,t=0;
      while(l<=r)if(sum[mid=(l+r)>>1]-sum[j]>=x)r=(t=mid)-1;else l=mid+1;
      if(!t){flag=0;break;}
    }
    if(flag&&sum[i+n-1]-sum[t]>=x)return 1;
  }
  return 0;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d%d",&n,&k);
    l=1,r=0;
    for(i=1;i<=n;i++)scanf("%d",&x),sum[i]=sum[n+i]=x,r+=x;r/=k;
    for(i=2;i<n*2;i++)sum[i]+=sum[i-1];
    while(l<=r)if(check(mid=(l+r)>>1))l=(ans=mid)+1;else r=mid-1;
    printf("%d\n",ans);
  }
  return 0;
}