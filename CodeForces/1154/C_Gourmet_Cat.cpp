#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int ans;
int a[5],b[5],d[]={0,1,2,0,2,1,0};

void work()
{
	a[0]=read();a[1]=read();a[2]=read();
	int m=min(min(a[0]/3,a[1]/2),a[2]/2);
	a[0]-=m*3,a[1]-=m*2,a[2]-=m*2;
	for(int i=0;i<=6;i++) 
    {
		int j=i,cur=0;
		for(int k=0;k<3;k++) b[k]=a[k];
		while(b[d[j]]>0) 
        {
			b[d[j]]--;
			j++;
            j%=7;
			cur++;
		}
		ans=max(ans,m*7+cur);
	}
	printf("%d\n",ans);
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
