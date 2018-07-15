#include <iostream>

using namespace std;

int n;
long long s[100003][3];
string str;

int main()
{
	cin>>n>>str;
	for(int i=n-1;i>=0;i--)//递推
	{
		for(int j=0;j<3;j++) 
			s[i][j]=s[i+1][j];
		if(str[i]=='W')
			s[i][2]+=1;
		else if(str[i]=='O')
			s[i][1]+=s[i+1][2];
		else if(str[i]=='C')
			s[i][0]+=s[i+1][1];
	}
	cout<<s[0][0]<<endl;
	return 0;
}

