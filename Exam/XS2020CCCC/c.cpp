#include<bits/stdc++.h>
#define LL long long

using namespace std;

int t;

void smallestGoodBase(long long N)
{
    LL n = N;
    LL ans = n - 1;
    for (int s = 59; s >= 2; --s)
    {
        int k = pow(n, 1.0 / s);
        if (k > 1)
        {
            LL sum = 1, mul = 1;
            for (int i = 1; i <= s; ++i)
            {
                mul *= k;
                sum += mul;
            }
            if (sum == n)
            {
                ans = k;
                break;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    long long n;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n;
        smallestGoodBase(n);
    }
    return 0;
}
