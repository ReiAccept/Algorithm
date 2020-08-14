#include<iostream>
#include<algorithm>

using namespace std;

int ans,n,num;
int a[103];

int main()
{
    while(cin>>num)
    {
        getchar();
        a[n++]=num;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        if(i!=n-1) cout<<"+";
        else cout<<endl;
    }
    return 0;
}
