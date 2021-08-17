#include<cmath>
#include<iostream>

using namespace std;

string s;
int minn=0x3f3f3f,maxn=-1;
int ax[30];

bool jud(int x)
{
	if(x==2)
		return true;
	if(x==0 || x==1)
		return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}

int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		ax[s[i]-'a']++;
	for(int i=0;i<=26;i++)
	{
		if(maxn<ax[i])
			maxn=ax[i];
		if(minn>ax[i] && ax[i]!=0)
			minn=ax[i];
	}
	int ans=maxn-minn;
	//for(int i=0;i<=26;i++)
	//	cout<<ax[i]<<" ";
	//cout<<endl<<ans<<endl;
	if(maxn==-1 || maxn==1)
	{
        cout<<"No Answer"<<endl;
        cout<<0<<endl;
        return 0;
    }
	if(jud(ans))
	{
		cout<<"Lucky Word"<<endl;
		cout<<ans<<endl;
	}
	else
	{
		cout<<"No Answer"<<endl;
		cout<<"0"<<endl;
	}
	return 0;
}
