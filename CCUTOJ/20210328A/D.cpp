#include<bits/stdc++.h>

using namespace std;

int n;

signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(((i+j)*(j-i+1))>>1==n)
                cout<<i<<" "<<j<<endl;
	return 0; 
}
