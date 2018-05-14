#include<iostream>

using namespace std;

int ping[21][21],flag[21],dp[21];
int n,x=1;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>ping[i][j];
        }
        flag[i]=1000000;
    }
    flag[n]=0;
    for(int i=n-1; i>=1; i--)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(ping[i][j]>0 && flag[j]!=1000000 && flag[i]>ping[i][j]+flag[j])
            {
                flag[i]=ping[i][j]+flag[j];
                dp[i]=j;
            }
        }
    }
    cout<<"minlong="<<flag[1]<<endl;
    cout<<1;
    while(x!=0)
    {
        x=dp[x];
        if(x==0)
            break;
        cout<<" "<<x;
    }

    return 0;
}
