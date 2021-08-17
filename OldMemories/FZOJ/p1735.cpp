#include <iostream>
#include <algorithm>
using namespace std;
int dp[5001];


struct node{
    int x,y;
}a[5001];

int cmp(node a,node b){
    return a.x<b.x;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        dp[i]=1;
    }
    sort(a,a+n,cmp);
    int maxk=0,res=0;
    for(int i=1;i<n;i++){
        maxk=0;
        for(int j=0;j<i;j++){
            if(a[j].y<a[i].y && dp[j]>maxk){
                maxk=dp[j];
            }
        }
        dp[i]=maxk+1;
        if(dp[i]>res)
            res=dp[i];
    }
    cout<<res<<endl;
    return 0;
}
