#include<iostream>

using namespace std;

string str;

bool check(char c)
{
	if(c=='a' || c=='o' || c=='u' || c=='i' || c=='e')
		return true;
	else
		return false;
}

int main()
{
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='n')
			continue;
		else if(check(str[i]))
			continue;
		else if(!check(str[i+1]))
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
