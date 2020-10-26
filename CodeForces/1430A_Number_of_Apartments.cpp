#include<bits/stdc++.h>
using namespace std;

int N,a,b,c;

void Solve(){
    cin>>N;
	a=b=c=0;
	if(N==1||N==2||N==4) return;
	if(N%3==0) a=N/3,b=0,c=0;
	if(N%3==1) a=(N-7)/3,b=0,c=1;
	if(N%3==2) a=(N-5)/3,b=1,c=0;
    if(a==0&&b==0&&c==0) puts("-1");
	else printf("%d %d %d\n",a,b,c);
}

int main()
{
    ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--) Solve();
	return 0;
}
