#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=2000+10;

int read() {
    int x; scanf("%lld",&x); return x;
}

int n;
char s[MAXN];
string ans;

string encode(int lst) { //最后一位
    int cnt=0;
    map<char,int> m;
    for(int i=lst;i>=1;i--) {
        if(!m.count(s[i])) {
            m[s[i]]=cnt;
            cnt++;
        }
    }
    string sx;
    for(int i=1;i<=lst;i++) {
        sx=sx+(char)('a'+m[s[i]]);
    }
    return sx;
}

signed main() {
    n=read();
    scanf("%s",s+1);
    ans=encode(1);
    for(int i=2;i<=n;i++) {
        ans=max(ans,encode(i));
        // encode(i);
    }
    cout<<ans<<endl;
    return 0;
}