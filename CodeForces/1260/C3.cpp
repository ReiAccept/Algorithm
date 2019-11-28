#include <bits/stdc++.h>

using namespace std;

int T, r, b, k;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&r,&b,&k);
        if (r>b) swap(r,b);
        int gx= __gcd(r,b);
        int tr=b/gx,tb=r/gx;
        --tr;
        if (tr/tb+(tr%tb !=0)>=k) printf("REBEL\n");
        else printf("OBEY\n");
    }
    return 0;
}
