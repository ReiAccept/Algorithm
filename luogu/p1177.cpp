#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int a[100003];

void Qsort(int low ,int high)
{
	if(low>=high)
		return;
	int first=low,last=high,key=a[first];
	while(first<last)
	{
		while(first<last && a[last]>=key)
			last--;
		a[first]=a[last];
		while(first<last && a[first]<=key)
			first++;
		a[last]=a[first];
	}
	a[first]=key;
	Qsort(low,first-1);
	Qsort(first+1,high);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//Qsort(1,n);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
