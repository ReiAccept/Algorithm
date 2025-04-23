#include<numeric>
#include<bits/stdc++.h>
#define int long long

using namespace std;

int ans=1;
bool f[23];

// int lcm(int a,int b) {
//     return a*b/__gcd(a,b);
// }

signed main() {
    for(int i=2;i<=20;i++) {
        ans=lcm(ans,i); //cpp17自带了
    }
    printf("%lld\n",ans);
    return 0;
}