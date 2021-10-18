#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll ok(ll need) {
	ll l = -5000, r = 5000, res = -12345678;
	while (r - l >= 0) {
		ll mid = (l + r) >> 1;
		ll tmp = mid * mid * mid;
		if (tmp == need) {
			return mid;
		}
		if (tmp > need) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

bool gao(int x) {
	int limit = 5000;	
	for (ll a = -limit; a <= limit; ++a) {
		for (ll b = -limit; b <= limit; ++b) {
			ll need = 1ll * x - a * a * a - b * b * b;
			ll c = ok(need);
			if (abs(c) <= 5000) {
				cout << a << " " << b << " " << c << endl;
				return true;
			}
		}
	}
	return false;
}

int main() {
	int cnt = 0;
	int Y = -12345678;
	for (int i = 0; i <= 200; ++i) {
		if (!gao(i)) {
			cout << Y << " " << Y << " " << Y << endl;
		}
	}
	cout << cnt << " " << cnt << " " << cnt << endl; 
	return 0;
}
