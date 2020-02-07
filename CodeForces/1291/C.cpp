#include <bits/stdc++.h>

using namespace std;

int T,n,m,k,ans;
int a[4007];

int read();

int main()
{
    T=read();
    while (T--)
    {
        n=read();
        m=read();
        k=read();
        if (k>=m) k=m-1;
        for (int i=1;i<=n;i++) a[i]=read();
        ans=0;
        for (int l=0;l<=k;l++)
        {
            int r=k-l,tmp=2e9;
            for(int i=0,j;i<=m-1-k;i++)
            {
                j=m-1-k-i;
                tmp=min(tmp,max(a[1+l+i],a[n-r-j]));
            }
            if(tmp>ans) ans=tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}


int read()
{
    int re=0,ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9')
    {
        re=re*10+ch-'0';
        ch=getchar();
    }
    return re;
}

