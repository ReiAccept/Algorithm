#include<iostream>

using namespace std;

string str;
int a0,a1,a2;

int main()
{
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='0')
			a0++;
		else if(str[i]=='1')
			a1++;
		else if(str[i]=='2')
			a2++;
	}
	if(a1==0 && a2==0)
	{
		cout<<str;
		return 0;
	}
	if(a0==0)
	{
		while(a1--)
			cout<<'1';
		while(a2--)
			cout<<'2';
		return 0;
	}
	if(a2==0)
	{
		while(a0--)
			cout<<'0';
		while(a1--)
			cout<<'1';
		return 0;
	}
	int cur=str.find('2');
	for(int i=0;i<cur;i++)
		if(str[i]=='0')
			cout<<'0';
	while(a1--)
		cout<<'1';
	while(cur<str.size())
	{
		if(str[cur]=='2')
			cout<<'2';
		if(str[cur]=='0')
			cout<<'0';
		cur++;
	}
	return 0;
}
