#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){
	char c; int num, f = 1;
	while(c = (char)getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
	while(c = (char)getchar(), isdigit(c)) num = num * 10 + c - '0';
	return num * f;
}

char r[300003];

void work()
{
    int n=read(),ans=0;
    bool f1=true,f2=true;
    scanf("%s",r);
    for(int i=0;i<n;i++)
    {
        if(r[i]=='<')f1=false;
        if(r[i]=='>')f2=false;
    }
    if(f1 || f2)
    {
        cout<<n<<endl;
    }
    else
    {
        if(r[0]=='-' || r[n-1]=='-') ans=1;
        for(int i=1;i<n;i++)if(r[i-1]=='-' || r[i]=='-')ans++;
        cout<<ans<<endl;
    }
    return;
}

signed main()
{
    int Case = read();
	while(Case--) work();
    return 0;
}
