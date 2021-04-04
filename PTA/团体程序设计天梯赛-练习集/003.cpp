#include<bits/stdc++.h>

using namespace std;

int n;
int r[10];
signed main()
{
    cin>>n;
    while(n)
    {
        r[n%10]++;
        n/=10;
    }
    return 0;
}