#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

const int MAXN = 3000;
const int MAXM = 3000;

int n, m, a[MAXN + 1], s[MAXN + 1];
long long f[MAXN + 1], g[MAXN + 1];

template <typename T>
inline T sqr(const T x) 
{
    return x*x; 
}

inline double slope(const int a, const int b) 
{
    return (double)(g[a]-g[b]+sqr(s[a])-sqr(s[b]))/(double)(s[a]-s[b]);
}

int main() 
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) 
        s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++) 
        f[i]=INT_MAX;
    for (int j=1;j<=m;j++) 
    {
        memcpy(g,f,sizeof(f));
        memset(f,0,sizeof(f));
        static int q[MAXN];
        int l=0,r=-1;
        q[++r]=0;
        for(int i=1;i<=n;i++)
        {
            while(l<r && slope(q[l+1],q[l])<2*s[i]) 
                l++;
            int t=q[l];
            f[i]=g[t]+sqr(s[i]-s[t]);
            while(l<r && slope(q[r],q[r-1])>slope(q[r],i)) 
                r--;
            q[++r]=i;
        }
    }
    printf("%d\n",(int)(f[n]*m-sqr(s[n])));
    return 0;
}
