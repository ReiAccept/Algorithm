#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
 
using namespace std;
 
int T,n,MAX;
int a[200003],sum[200003];
map<int,int> mp;
 
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        MAX=0;
        mp.clear();
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",a+i);
            ++sum[a[i]];
        }
        for(int i=0;i<=n;++i)
            if(sum[i])
            {
                ++mp[sum[i]];
                if(sum[i]>MAX) MAX=sum[i];
            }
        cout<<(mp[MAX]-1)+(n-mp[MAX]*MAX)/(MAX-1)<<endl;
    }
    return 0;
}
