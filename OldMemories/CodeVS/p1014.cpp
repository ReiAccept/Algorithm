#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int v,n,tmp;
    vector <int> a;
    cin>>v>>n;
    int F[v]={0};
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++)
        for(int j=v;i>a[i];j--)
            F[j]=max(F[j],F[j-a[i]]+a[i]);
    cout<<v-F[v]<<endl;
    return 0;
}
