#include<bits/stdc++.h>
#define MN 500

using namespace std;

typedef long double ld;
const ld pai = acos(-1);

int n,m;

ld len,ans;
ld f[MN+5];

int main()
{
	scanf("%d%d",&n,&m);
	ld d = pai/m; 
	for(int i=1;i<m;i++)
    {
		if(i*d>2)len+=2;
		else len+=i*d;
	}
	len*=2;
	len+=2;
	for(int i=1;i<=n;i++)
    {
		f[i]=len*i+2*m*(i-1)+1+f[i-1];
		ans += m*(f[i]*2-i*len);
	}
    if(m==1) ans-=(2+2*n)*n/2;
	printf("%.10lf\n",(double)ans);
}

