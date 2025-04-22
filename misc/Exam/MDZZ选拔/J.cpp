#include<iostream>
#include<algorithm>

using namespace std;  

int T;
int a[45];

int main()
{
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        cout<<(100-a[0])*(100-a[0])<<endl;
    }
    return 0;
}
