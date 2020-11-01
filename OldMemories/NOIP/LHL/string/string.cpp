#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int ans,m,n;
int pos[833];
char s[833];

inline int cs(char s)
{
    return s-'A'+1;
}

inline int calc(int l,int r)
{
    if(l==r) return 0;
    if(l==r-1) return pos[r]-pos[l]-1;
    return calc(l+1,r-1)+pos[r]-pos[l]-(r-l);
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%s",s+1);
    scanf("%d",&m);
    n=strlen(s+1);
    for(int i=1;i<=26;i++)
    {
        int tmp=0;
        for(int j=1;j<=n;j++)
            if(cs(s[j])==i) pos[++tmp]=j;
        if(tmp==1){
            ans=max(ans,1);
            continue;
        }
        int now=-2147483644;
        for(int j=1;j<=tmp;j++)
            for(int l=j+1;l<=tmp;l++)
                if(calc(j,l)<=m) now=max(now,l-j+1);
        ans=max(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}
