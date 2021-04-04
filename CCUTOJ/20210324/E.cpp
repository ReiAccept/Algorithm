#include <bits/stdc++.h>

using namespace std;

int T,a,b;

signed main() {
    ios::sync_with_stdio(false);
	cin>>T;
	while (T--) {
		cin>>a>>b;
		cout<<(b-a)-(b/12-a/12)<<endl;
	}
	return 0;
}
