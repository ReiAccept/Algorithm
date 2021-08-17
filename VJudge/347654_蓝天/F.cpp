#include<iostream>

using namespace std;

int n,T;
int a[400003];

int main()
{
    cin>>T;
    while(T--)
    {
        bool flag=true;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int i,j,k=-1,m=n/2;
        for(i=2;i<=n;i++) if(a[i]!=a[i-1]) break;
        if((m-(i-1))/2<=i-1) flag = false;
        for(j=m;j>=i;j--) if(a[j]>a[j+1]) break;
        for(int i2=i+1;i2<=j;i2++)
            if(a[i2]<a[i2-1] && i2-i>i-1)
            {
                k=i2;
                break;
            }
        if(k==-1) flag=false;
        if(i-1>=k-i || i-1>=j-k+1) flag=false;
        if(!flag) cout<<"0 0 0"<<endl;
        else cout<<i-1<<' '<<k-i<<' '<<j-k+1<<endl;
    }
    return 0;
}
