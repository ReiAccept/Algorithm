#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,sum;
int x[100003],h[100003];

void work()
{
    n=read();
    for(int i=1;i<=n;i++){
        x[i]=read();h[i]=read();
    }
    for(int i=2;i<n;i++){
            if(x[i]-h[i]>x[i-1])sum++;
            else if(x[i]+h[i]<x[i+1]){
                sum++;
                x[i]+=h[i];
            }
        }
    printf("%d\n",n==1?1:sum+2);
    return;
}

signed main()
{
    int Case = 1;//read();
	while(Case--) work();
    return 0;
}
