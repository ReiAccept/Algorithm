#include <bits/stdc++.h>

using namespace std;

int T,n;

int main() 
{
	cin >> T;
	while (T--) 
    {
		cin >> n;
		int ans = 1e9;
		for (int x=1; x*x<=n; x++) ans=min(ans, x-1+((n-x)+x-1)/x);
		cout << ans << endl;
	}
	return 0;
}
