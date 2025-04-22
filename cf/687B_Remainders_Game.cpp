#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

const int N = 1200021;

int cntP[N], isP[N];
bool flag = true;

void INIT()
{
    for(int i=2;i<N;i++) if(!isP[i]) for(int j=i;j<N;j+=i) isP[j]=i;
}

void work()
{
    int n=read(),k=read();
    for(int i=1;i<=n;i++)
    {
        int x=read();
        while(x>1)
        {
            int p=isP[x];
            int cnt=0;
            while(!(x%p))
            {
                cnt++;
                x /= p;
            }
            cntP[p]=max(cntP[p], cnt);
        }
    }
    while(k>1)
    {
        flag &=(cntP[isP[k]]>0);
        cntP[isP[k]]--;
        k /= isP[k];
    }
    if(flag)printf("Yes\n");
    else printf("No\n");
    return;
}

signed main()
{
    INIT();
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
