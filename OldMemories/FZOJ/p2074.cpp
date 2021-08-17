#include <iostream>

using namespace std;

int n,m,x1,x2,y1,y2;

int main()
{
	cin>>n>>m>>x1>>y1>>x2>>y2;
	int y=min(m-y1+m-y2,y1+y2);
	int x=min(n-x1+n-x2,x1+x2);
	if((x1==x2) && (x1==0 || x1==n))
	{
		x=0;
		y=y1-y2>0?y1-y2:-(y1-y2);
	}
	if((y1==y2) && (y1==0 || y1==m))
	{
		y=0;
		x=x1-x2>0?x1-x2:-(x1-x2);
	}
	cout<<x+y<<endl;
	return 0;
}

