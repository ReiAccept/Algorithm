#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}
 
int m,n;
double area;
 
struct Point 
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}V[1003][60];
typedef Point Vector;
Vector operator - (Point A,Point B) { return Vector(A.x-B.x,A.y-B.y); }
Vector operator * (Vector A,double p) { return Vector(A.x*p,A.y*p); }
inline double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
double DBXMJ(Point p[], int n,double areaT=0){for(int i=1;i<n-1;i++) areaT+=Cross(p[i]-p[0],p[i+1]-p[0]);return fabs(areaT/2);}
 
void Solve()
{
    m=qrd();
    for(int i=0;i<m;i++)
    {
        n=qrd();
        for(int j=0;j<n;j++) cin>>V[i][j].x>>V[i][j].y;
        area+=DBXMJ(V[i],n);
    }
    printf("%lld\n",(long long)area);
    return;
}
 
int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
