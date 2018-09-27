#include <iostream>

using namespace std;

long long n,A,B,C,D;
char a[100003],b[100003];
long long ans;

int main()
{
    cin>>n;
	cin>>(a+1)>>(b+1);
	for(int i=1;i<=n;i++)
    {
		if(a[i]=='1')
        {
			if(b[i]=='0')
                B++;//A1B0
			else 
                D++;//A1B1
		}
        else
        {
			if(b[i]=='0')
                C++;//A0B0
			else 
                A++;//A0B1
		}
	}
	ans=A*B;
	ans+=B*C;
	ans+=C*D;
	cout<<ans<<endl;
	return 0;
}
/*
#include<iostream>

using namespace std;

long long ans;
int n,suma1,suma0;
char a[100003],b[100003];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]=='1')
            suma1++;
    }
    suma0=n-suma1;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='0' && b[i]=='0')
            ans+=(suma1-1);
        if(a[i]=='1' && b[i]=='0')
            ans+=suma0;
    }
    cout<<ans<<endl;
    return 0;
}
*/
