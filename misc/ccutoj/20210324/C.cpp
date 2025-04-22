#include <bits/stdc++.h>
using namespace std;
int T,n,l,r,opt;
int a[1003];
signed main(){
    ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>T;
	while(T--) {
		cin>>l>>r>>opt;
		if(opt==1) sort(a+l,a+1+r);
		else sort(a+l,a+1+r,[](int a,int b){return a>b;});
		for(int i=l;i<=r;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}

