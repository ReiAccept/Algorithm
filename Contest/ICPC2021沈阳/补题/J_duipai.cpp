#include <bits/stdc++.h>

using namespace std;

namespace AC {
int ans;
int a[5], b[5], d[5];

int work(string ta,string tb) {
    // string ta, tb;
    // cin >> ta >> tb;
    for (int i = 0; i < 4; i++) {
        a[i + 1] = ta[i] - '0';
        b[i + 1] = tb[i] - '0';
    }
    for (int i = 1; i <= 4; i++) {
        d[i] = a[i] - b[i];
    }
    for (int i = 4; i >= 1; i--) {
        d[i] -= d[i - 1];
    }
    for (int i = 1; i <= 4; i++) {
        d[i] = (d[i] % 10 + 10) % 10;
    }
    ans = 20;
    for (int j = 0; j < 16; j++) {
        int ut = 0, dt = 0;
        for (int i = 1; i <= 4; i++) {
            if (j & (1 << (i - 1))) {
                ut += (10 - d[i]) % 10;
            } else {
                dt += d[i];
            }
        }
        ans = min(ans, max(ut, dt));
    }
    return ans;
    // printf("%d\n", ans);
}
};

namespace WA {
int ap[5], bp[5];
int du[5], dd[5];
int ss[5], c[5], s[5];
int ans;
void dfs(int dep) {
    if (dep == 5) {
        int cnt = 0;
        for (int i = 1; i <= 4; i++) { //正数处理
            if (s[i] < 0)
                ss[i] = 0;
            else
                ss[i] = s[i];
            c[i] = ss[i] - ss[i - 1];
            if (c[i] >= 0)
                cnt += c[i];
        }
        for (int i = 1; i <= 4; i++) { //负数处理
            if (s[i] < 0)
                ss[i] = -s[i];
            else
                ss[i] = 0;
            c[i] = ss[i] - ss[i - 1];
            if (c[i] >= 0)
                cnt += c[i];
        }
        ans = min(ans, cnt);
        return;
    }
    s[dep] = (-du[dep]);
    dfs(dep + 1);
    s[dep] = dd[dep];
    dfs(dep + 1);
}

int work(string a,string b) {
    if (a == b) {
        return 0;
    }
    memset(s, 0, sizeof(s));
    memset(ss, 0, sizeof(ss));
    ans = 20;
    for (int i = 4; i >= 1; i--) {
        ap[i] = a[i - 1] - '0';
        bp[i] = b[i - 1] - '0';
        du[i] = ap[i] - bp[i];
        if (du[i] < 0)
            du[i] += 10;
        dd[i] = bp[i] - ap[i];
        if (dd[i] < 0)
            dd[i] += 10;
    }
    dfs(1);
    swap(a, b);
    memset(s, 0, sizeof(s));
    memset(ss, 0, sizeof(ss));
    for (int i = 4; i >= 1; i--) {
        ap[i] = a[i - 1] - '0';
        bp[i] = b[i - 1] - '0';
        du[i] = ap[i] - bp[i];
        if (du[i] < 0)
            du[i] += 10;
        dd[i] = bp[i] - ap[i];
        if (dd[i] < 0)
            dd[i] += 10;
    }
    dfs(1);
    return ans;
}
};

signed main() {
    freopen("duipai.txt","w",stdout);
    int T=1;
    long long ac=0,wa=0;
    for (int CASE = 1; CASE <= T; CASE++) {
        for(int i=1000; i<=9999; i++) {
            for(int j=1000; j<=9999; j++) {
                if(AC::work(to_string(i),to_string(j))==WA::work(to_string(i),to_string(j))) {
                    // cout<<i<<" "<<j<<" AC"<<endl;
                    ac++;
                } else {
                    cout<<i<<" "<<j<<" WA"<<endl;
                    cout<<"AC Answer is: "<<AC::work(to_string(i),to_string(j))<<endl;
                    cout<<"WA Answer is: "<<WA::work(to_string(i),to_string(j))<<endl;
                    wa++;
                }
            }
        }

    }
    cout<<"TOTAC: "<<ac<<" TOTWA: "<<wa<<endl;
    return 0;
}
