#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n,ans,m;
int a[5003];
bool vis[5003];


int main(){
    freopen("box.in","r",stdin);
    freopen("box.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        if (!vis[i])
		{
            ans++;
            m=1;
            vis[i]=true;
            for (int j=i+1;j<=n;j++)
                if ((!vis[j]) && (a[j]>=m))
				{
                    vis[j]=true;
                    m++;
                }
        }
    cout<<ans<<endl;
	return 0;
}
