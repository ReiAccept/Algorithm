#include <bits/stdc++.h>

using namespace std;

int ans;

signed main() {
    for(int i=1;i<1000;i++) {
        if(i%3==0 || i%5==0) {
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}