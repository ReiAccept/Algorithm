#include<bits/stdc++.h>
#define int long long
#define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
const int Q=(1<<24)+1;
char in[Q],*is=in,*it=in,c;
void read(long long &n){
  for(n=0;(c=gc())<'0'||c>'9';);
  for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
}

using namespace std;

const int MAXN=1e6+3;

int n,m;
int a[MAXN<<1];
bool vis[MAXN];
bool check(int x)
{
    int cnt=a[1];
    int cc=0,c=1;//1 从水晶往后跳，0 非水晶往后跳
    for(int i=2;i<=2*m;i++)
    {
        if(a[i]>=cnt+x) //跳不到
        {
            if(!c)return false; 
            cnt+=x;
            if(cnt==a[i])c=1;
            else c=0;
        }
        else //跳的到
        {
            if(c==1)cnt=a[i];
            else if(c==0)
            {
                cnt=min(a[i+1]-1,cnt+x);
                if(cnt==a[i])c=1;
            }
            if(i>m)
            {
                if(!vis[i-m])cc++;
                vis[i-m]=true;
            }
            else 
            {
                if(!vis[i])cc++;
                vis[i]=true;
            }
        }
        if(cc==m)return true;
    }
    return false;
}

void work() {
    read(n); read(m);
    int l=1,r=n;
    for(int i=1;i<=m;i++) {
        read(a[i]);
        a[i+m]=a[i]+n;
    }
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return;
}

signed main() {
    int T=1;
    for(int CASE=1;CASE<=T;CASE++) {
        // printf("CASE:%lld\n",CASE);
        work();
    }
    return 0;
}