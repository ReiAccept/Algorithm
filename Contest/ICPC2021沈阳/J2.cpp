#include<bits/stdc++.h>
#define int long long

using namespace std;

// const int MAXN=2000+10;

// int a,b;
int ap[5],bp[5];
int du[5],dd[5];
int ss[5],c[5],s[5];
int ans;
// int tot;
void dfs(int dep)
{
    if(dep==5)
    {
        // tot++;
        // printf("SS:%d %d %d %d\n",s[1],s[2],s[3],s[4]);
        int cnt=0;
        for(int i=1;i<=4;i++) //正数处理
        {
            if(s[i]<0) ss[i]=0;
            else ss[i]=s[i];
            c[i]=ss[i]-ss[i-1];
            if(c[i]>=0) cnt+=c[i];
        }
        for(int i=1;i<=4;i++) //负数处理
        {
            if(s[i]<0) ss[i]=-s[i];
            else ss[i]=0;
            c[i]=ss[i]-ss[i-1];
            if(c[i]>=0) cnt+=c[i];
        }
        // cout<<cnt<<endl;
        // ans=min(ans,cnt);
        // printf("SS:%d %d %d %d\n",ss[1],ss[2],ss[3],ss[4]);
        // if(cnt!=0) 
        ans=min(ans,cnt);
        return;
    }
    s[dep]=(-du[dep]);
    dfs(dep+1);
    s[dep]=dd[dep];
    dfs(dep+1);
}

string a,b;

void work() {
    // scanf("%d%d",&a,&b);
    cin>>a>>b;
    if(a==b) {
        cout<<0<<endl;
        return;
    }
    // string ta=a,tb=b;
    memset(s,0,sizeof(s));
    memset(ss,0,sizeof(ss));
    ans=20;
    for(int i=4;i>=1;i--) {
        ap[i]=a[i-1]-'0'; bp[i]=b[i-1]-'0';
        // a/=10; b/=10;
        du[i]=ap[i]-bp[i];
        if(du[i]<0)du[i]+=10;
        dd[i]=bp[i]-ap[i];
        if(dd[i]<0)dd[i]+=10;
    }
    // for(int i=1;i<=4;i++) {
    //     printf("du : %lld, dd: %lld\n",du[i],dd[i]);
    // }
    dfs(1);
    // b=ta,a=tb;
    swap(a,b);
    memset(s,0,sizeof(s));
    memset(ss,0,sizeof(ss));
    for(int i=4;i>=1;i--) {
        // ap[i]=a%10; bp[i]=b%10;
        // a/=10; b/=10;
        ap[i]=a[i-1]-'0'; bp[i]=b[i-1]-'0';
        du[i]=ap[i]-bp[i];
        if(du[i]<0)du[i]+=10;
        dd[i]=bp[i]-ap[i];
        if(dd[i]<0)dd[i]+=10;
    }
    dfs(1);
    // printf("%d\n",ans);
    cout<<ans<<endl;
    return;
}

signed main() {
    int T=1;
    // scanf("%d",&T);
    cin>>T;
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}