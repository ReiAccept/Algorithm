#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

double x;

int main()
{
    scanf("%lf",&x);
    if(x>0 && x<1)
        x=10-x*x;
    else if(x>=1 && x<=4)
        x=10-x;
    else if(x>4 && x<25)
        x=10-2*sqrt(x);
    printf("%.2lf",x);
    return 0;
}
