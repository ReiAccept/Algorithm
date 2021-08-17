#include<iostream>

using namespace std;

int n,m,a,s,start=1;
bool k[100001]; 
string name[100001];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>k[i]>>name[i];
    for(int i=1;i<=m;i++)
    {
        cin>>a>>s;
            int step0=s%n;
    	if((a+k[start])%2==0) 
    	{
        	start-=step0;
        	if(start<=0)
				start+=n;
    	}
    	else
    	{
        	start+=step0;
        	if(start>n)
				start-=n;
    	}
    }
    cout<<name[start]<<endl;
}

