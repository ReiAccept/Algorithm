#include<iostream>
#include<algorithm>

using namespace std;

int n,ans;
int a[103];
bool d[103];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!d[i]){
            ans++;
            for(int j=i+1;j<=n;j++){
                if(d[i] || (a[j] % a[i]==0)){
                    d[j]=true;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
