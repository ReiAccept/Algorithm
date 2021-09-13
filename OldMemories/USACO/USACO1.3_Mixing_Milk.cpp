#include <iostream>
#include <algorithm>
using namespace std;
struct good{
	int x;
	int y;
}a[200001];
int comp(const good &a,const good &b)
{ 
	if (a.x<b.x) 
		return 1;
	return 0;
}
int main()
{
	int n,m,b=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y;
	sort(a+1,a+m+1,comp);
	for(int i=1;i<=m;i++)
	{
	    b=b+a[i].y;
		if(b<n)
		{
			c+=a[i].y*a[i].x;
		}
		else
		{
			c=c+(a[i].y-b+n)*a[i].x;
			cout<<c;
			return 0;
		}
    } 
}
