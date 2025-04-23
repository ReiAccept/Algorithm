/*
B=_#__|__#_|_#__
0:空格
1:障碍
//将模板A翻转
0:空格
1:船只

f[i]=sum(A[j]*B[i])
对于模板任何一个船只，它不能碰到障碍
即A*B等于0即可

v[i]表示i可以作为起点
g[i]表示i这个位置能否被覆盖
for(i=0;i<n;i++)
  for(j=0;j<m;j++)ok[i+j]+=v[i]*A[j]
  
FFT
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=705,M=N*N,MAXL=1100000;
const double pi=acos(-1.0);
int Case;
int n,m,i,j,k,H,W,len,all,S[M],T[M],sx,sy;char a[N][N];
int h,t,q[M][2],ans;bool v[M],g[M];
int pos[MAXL];
struct comp{
  double r,i;comp(double _r=0,double _i=0){r=_r,i=_i;}
  comp operator+(const comp&x){return comp(r+x.r,i+x.i);}
  comp operator-(const comp&x){return comp(r-x.r,i-x.i);}
  comp operator*(const comp&x){return comp(r*x.r-i*x.i,r*x.i+i*x.r);}
  comp conj(){return comp(r,-i);}
}A[MAXL],B[MAXL];
void FFT(comp a[],int n,int t){
  for(int i=1;i<n;i++)if(i<pos[i])swap(a[i],a[pos[i]]);
  for(int d=0;(1<<d)<n;d++){
    int m=1<<d,m2=m<<1;
    double o=pi*2/m2*t;comp _w(cos(o),sin(o));
    for(int i=0;i<n;i+=m2){
      comp w(1,0);
      for(int j=0;j<m;j++){
        comp&A=a[i+j+m],&B=a[i+j],t=w*A;
        A=B-t;B=B+t;w=w*_w;
      }
    }
  }
  if(t==-1)for(int i=0;i<n;i++)a[i].r/=n;
}
void init(){
  int xl=N,xr=0,yl=N,yr=0;
  for(i=0;i<n;i++)for(j=0;j<m;j++)if(a[i][j]=='o'){
    xl=min(xl,i);
    xr=max(xr,i);
    yl=min(yl,j);
    yr=max(yr,j);
  }
  H=xr-xl+1,W=yr-yl+1;
  for(i=xl;i<=xr;i++)for(j=yl;j<=yr;j++)if(a[i][j]=='o')S[(i-xl)*m+j-yl]=1;
  len=(xr-xl)*m+yr-yl+1;
  sx=xr,sy=yr;
  for(i=0;i<n;i++)for(j=0;j<m;j++)if(a[i][j]=='#')T[i*m+j]=1;
}
inline void ext(int x,int y){
  if(x<0||x>=n||y<0||y>=m)return;
  int z=x*m+y;
  if(!g[z]||v[z])return;
  v[z]=1;
  q[++t][0]=x;
  q[t][1]=y;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
  n=m=i=j=k=H=W=len=all=sx=sy=h=t=ans=0;
  memset(S,0,sizeof S);
  memset(T,0,sizeof T);
  memset(a,0,sizeof a);
  memset(q,0,sizeof q);
  memset(v,0,sizeof v);
  memset(g,0,sizeof g);
  memset(pos,0,sizeof pos);
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++)scanf("%s",a[i]);
  init();
  all=n*m;
  for(k=1;k<all;k<<=1);k<<=1;
  j=__builtin_ctz(k)-1;
  for(i=0;i<k;i++)pos[i]=pos[i>>1]>>1|((i&1)<<j);
  for(i=0;i<k;i++)A[i]=comp(0,0);
  for(i=0;i<len;i++)if(S[i])A[len-i-1].r=1;
  for(i=0;i<all;i++)if(T[i])A[i].i=1;
  FFT(A,k,1);
  for(i=0;i<k;i++){
    j=(k-i)&(k-1);
    B[i]=(A[i]*A[i]-(A[j]*A[j]).conj())*comp(0,-0.25);
  }
  FFT(B,k,-1);
  for(i=H-1;i<n;i++)for(j=W-1;j<m;j++)if(B[i*m+j].r<0.5)g[i*m+j]=1;
  h=1,t=0;
  ext(sx,sy);
  while(h<=t){
    sx=q[h][0];sy=q[h++][1];
    ext(sx-1,sy);
    ext(sx+1,sy);
    ext(sx,sy-1);
    ext(sx,sy+1);
  }
  for(i=0;i<k;i++)A[i]=comp(0,0);
  for(i=0;i<len;i++)if(S[i])A[i].r=1;
  for(i=0;i<all;i++)if(v[i])A[i].i=1;
  FFT(A,k,1);
  for(i=0;i<k;i++){
    j=(k-i)&(k-1);
    B[i]=(A[i]*A[i]-(A[j]*A[j]).conj())*comp(0,-0.25);
  }
  FFT(B,k,-1);
  for(i=0;i<k;i++)if(B[i].r>0.5)ans++;
  printf("%d\n",ans);
  }
  return 0;
}