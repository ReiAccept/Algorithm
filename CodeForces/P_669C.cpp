#include<iostream>

using namespace std;

const int MAXN=103;

int n,flag;
int a[MAXN],dp[MAXN];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) if(!a[i]) dp[i]=dp[i-1]+1,flag=0;
        else
        {
            if(a[i]==3) dp[i]=dp[i-1],flag=3-flag;
            else
            {
                if(a[i]==flag) dp[i]=dp[i-1]+1,flag=0;
                else dp[i]=dp[i-1],flag=a[i];
            }
        }
    cout<<dp[n]<<endl;
}
