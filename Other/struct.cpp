#include <iostream>

using namespace std;

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};

Point operator + (const Point A,const Point B){
    return Point(A.x+B.x,A.y+B.y);
}

Point m1,m2;

int main()
{
    m1.x=99;
    m1.y=99;
    m2.x=99;
    m2.y=99;
    m1=m1+m2;
    cout<<m1.x<<endl;
    return 0;
}