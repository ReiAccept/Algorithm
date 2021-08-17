#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s[1003];

bool cmp(string a,string b)
{
	return a+b>b+a;
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) 
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++) 
		cout<<s[i];
	return 0;
}
