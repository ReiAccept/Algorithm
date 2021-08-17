#include<cstdio>
#include<iostream>

using namespace std;

int n,x,m;
int h[100003][3];

int main()
{
    freopen("drive.in","r",stdin);
    //freopen("drive.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i][0];
    cin>>x>>m;
    for(int i=1;i<=n;i++)
    {
        int chax=0x3f3f3f3f;
        for(int j=1+1;j<=n;j++)
        {
            int cha=h[i][0]-h[j][0];
            if(cha<0) cha=(-cha);


        }
    }
    for(int i=1;i<=m;i++)
    {
        
    }
    return 0;
}
