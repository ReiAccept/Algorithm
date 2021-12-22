#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e6+3;

int n;
int tot=0;
char s[MAXN];
//priority_queue<int, vector<int>, greater<int> > a,b;
// stack<int>a,b;
int cnt0,cnt1,ans;

void work() {
    n=read();
    cnt0=cnt1=ans=0;
    scanf("%s",s+1);
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='1')
        {
            if(cnt0)
            {
                cnt0--;
                ans+=i;
            }
            else if(cnt1)
            {
                cnt1--;
                ans+=i;
            }
            else cnt1++;
        }
        else cnt0++;
    }
    printf("%lld\n",ans);
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}