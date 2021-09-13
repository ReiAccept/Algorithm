#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n;

void work()
{
    n=read();
	vector<int> a(n);
	for (int i=0;i<n;i++)a[i]=read();
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(),a.end())-a.begin());
	if (a.size()>3)
    {
		printf("-1\n");
        return;
	} 
		if (a.size()==1)printf("0\n");
        else if (a.size()==2) 
        {
			if (!((a[1]-a[0])%2)) printf("%d\n",(a[1]-a[0])/2);
            else printf("%d\n",a[1]-a[0]);
		} 
        else 
        {
			if (a[1]-a[0]!=a[2]-a[1]) printf("-1\n");
            else printf("%d\n",a[1]-a[0]);
		}
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
