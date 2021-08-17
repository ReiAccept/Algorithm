#include <bits/stdc++.h>

using namespace std;

const double pi=acos(-1.0);
double n, m;

int main()
{
    scanf("%lf%lf", &n, &m);
    double k=floor(2.0*m/pi);
    double t=pi/m*(1.0+k)*k+4.0*(m-k)-2.0;
    double ans=t*n*(n+1.0)*(n+2.0)/6.0+m*(n-1)*n*(n+1)/3.0+n*(n+1)/2.0;
    ans=ans*2.0*m-m*n*(n+1)*t/2.0;
    if(m==1) ans-=n*(n+1.0);
    printf("%.8f\n", ans);
    return 0;
}
