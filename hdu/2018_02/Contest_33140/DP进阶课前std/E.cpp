#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=20010,M=210;
const int inf=~0U>>1;
int Case,n,m,i,j,o,a[N],s[N],f[N][M];
inline void up(int&a,int b){a<b?(a=b):0;}
int main(){
    scanf("%d",&Case);
    while(Case--){
        scanf("%d",&n);
        m=(int(sqrt(n*2))+5);
        //printf("%d\n",m);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
        for(i=1;i<=m;i++)f[n+1][i]=0;
        for(i=n;i;i--){
            for(j=1;j<=m;j++){
                f[i][j]=-inf;
                if(i+j-1>n){f[i][j]=0;continue;}
                if(i+j-1<=n){
                    up(f[i][j],s[i+j-1]-s[i-1]-f[i+j][j]);
                }
                if(i+j<=n&&j<m){
                    up(f[i][j],s[i+j]-s[i-1]-f[i+j+1][j+1]);
                }
                //printf("f[%d][%d]=%d\n",i,j,f[i][j]);
            }
        }
        printf("%d\n",f[1][1]);
    }
}