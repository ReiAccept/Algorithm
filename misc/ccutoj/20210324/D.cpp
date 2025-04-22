#include<bits/stdc++.h>
using namespace std;

int n;
int fib[30]={0,1,1};
bool a[100003];

signed main(){
    ios::sync_with_stdio(false);
    for(int i=3;i<=25;i++) fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<=25;i++) a[fib[i]]=true;
	while(cin>>n){
        if(a[n]) cout<<"Sakiya is so noob."<<endl;
		else cout<<"Hans_Moe is so dalao."<<endl;
    }
	return 0;
}
