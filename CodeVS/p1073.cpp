#include <bits/stdc++.h>

using namespace std;

int pre[5001];

int find(int x)
{
    while(pre[x]!=x)
        x=pre[x];
    return x;
}

void hebing(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
	    pre[fx]=fy;
}

int main()
{
    int n,p,m,a,b;
    cin>>n>>p>>m;
    for(int i=1;i<=n;i++)
        pre[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        hebing(a,b);
    }
    for(int i=i;i<=p;i++)
    {
        cin>>a>>b;
        if(find(a)!=find(b))
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
}