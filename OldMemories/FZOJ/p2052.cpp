#include<cstdio>
#include<iostream>

using namespace std;

string s1,s2;

void Build(int l1,int r1,int l2,int r2)
{
	int m=s2.find(s1[l1]);
	if (m==-1) 
		return;
	if (m>l2) 
		Build(l1+1,l1+m-l2,l2,m-1);
	if (m<r2) 
		Build(l1+m-l2+1,r1,m+1,r2);
	printf("%c",s1[l1]);
}

int main()
{
	cin>>s1>>s2; 
	s1=' '+s1,s2=' '+s2;
	Build(1,s1.size(),1,s2.size());
	return 0;
}
