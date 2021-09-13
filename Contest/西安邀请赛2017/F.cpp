#include<bits/stdc++.h>

using namespace std;

int n,m;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    while(cin>>n>>m)
    {
        if(n==0) printf("0.00000\n");
        else if(m==0) printf("1.00000\n");
        //else if(n==m) printf("0.50000\n");
        else
        {
            printf("%.5lf",(double)n/double(n+m));
        }
    }
    return 0;
}