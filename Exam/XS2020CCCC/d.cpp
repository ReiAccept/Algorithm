#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>a;
int main()
{
    cin>>n;
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        a.insert(upper_bound(a.begin(),a.end(),x),x);//二分插入保证单调性
        if(i%2){
            printf("%d ",a[(i-1)/2]);
        }else{
            printf("%d ",(a[i/2]+a[(i-1)/2])/2);
        }
    }
    return 0;
}
