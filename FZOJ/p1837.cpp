#include<cstdio>

using namespace std;

int n,m,res,s;
int a[100][100],b[3][100];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
        for(int j=1; j<=2; j++)
            scanf("%d",&a[i][j]);
    for(int i=1; i<=m; i++)
    {
        b[a[i][1]][1]=a[i][1];
        b[a[i][1]][3]++;
        b[a[i][2]][1]=a[i][2];
        b[a[i][2]][2]++;
    }
    for(int i=1; i<=m; i++)
    {
        b[a[i][1]][3]=b[a[i][1]][3]+b[a[i][2]][3];
        b[a[i][2]][2]=b[a[i][2]][2]+b[a[i][1]][2];
    }
    for(int i=1; i<=n; i++)
        if(b[i][2]>=(n/2+1)||b[i][3]>=(n/2+1))
            res++;
    printf("%d",res);
    return 0;
}
/*
#include<iostream>
using namespace std;
int n,m,mp[105][105],a,b,res;

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        mp[a][b]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][k]&&mp[k][j]){
                    mp[i][j]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[0][j]+=mp[i][j];
            mp[i][0]+=mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(mp[0][i]>n/2 || mp[i][0]>n/2)
            res++;
    }
    cout<<res<<endl;
    return 0;
}
*/
