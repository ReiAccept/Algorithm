#include<cstdio>
#include<algorithm>

using namespace std;

int n,a,b,days;
int w[500003];

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",w+i);
    sort(w+1,w+1+n);
    while(true)
    {
        w[n]-=b; days++;
        for(int i=n;i>=1;i--) 
            if(w[i]<w[i-1]) swap(w[i-1],w[i]);
            else break;
        if(a*days>=w[n] && a*days>=w[n-1])
        {
            printf("%d\n",days);
            break;
        }
    }
    return 0;
}
