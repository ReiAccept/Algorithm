#include<cstdio>
#include<iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    if(n==1 || n==2) cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        if(n%2)
        {
            printf("1 %d\n%d ",n,n-1);
            for(int i=1; i<=n-1; i++) printf("%d ",i);
        }
        else
        {
            printf("1 %d\n%d ",n/2,n-1);
            for(int i=1; i<=n; i++) if(i!=n/2) printf("%d ",i);
        }
    }
    return 0;
}
