#include<iostream>

using namespace std;

int i;
string s,t;

int main()
{
	cin>>s>>t;
	for(i=1;i<=s.size() && i<=t.size();i++)
	{
		if(s[s.size()-i]!=t[t.size()-i])
		{
			break;
		}
	}
	i--;
	cout<<s.size()-i+t.size()-i<<endl;
	return 0;
}
