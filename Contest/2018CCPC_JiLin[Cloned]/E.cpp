#include<bits/stdc++.h>

using namespace std;

int T,Case;

double deta(double a,double b,double c)
{
    double ans=b*b-4*a*c;
    ans=sqrt(ans);
    return ans;
}

int main()
{
    cin>>T;
    double r,h,x0,y0,z0,vx,vy,vz;
    while(T--)
    {
        cin>>r>>h;
        cin>>x0>>y0>>z0;
        cin>>vx>>vy>>vz;
        double a=vx*vx+vy*vy-vz*vz*r*r/(h*h);
        double b=2*x0*vx+2*y0*vy+2*r*r*vz/h-2*z0*vz*r*r/(h*h);
        double c=x0*x0+y0*y0-r*r+2*r*r*z0/h-r*r*z0*z0/(h*h);
        double t2=(-b-deta(a,b,c))/(2*a);
        printf("Case %d: %.10lf\n",++Case,t2);
    }
    return 0;
}
