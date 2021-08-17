#include<bits/stdc++.h>

using namespace std;

int n;
int a[4];

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    while(cin>>n)
    {
        cin>>a[1]>>a[2]>>a[3]; int r=(a[1]%2)+(a[2]%2)+(a[3]%2);
        if(r==0){ //all even
            for(int tmp,i=4;i<=n;i++){
                cin>>tmp;
                if(tmp%2) cout<<tmp<<endl;
            }
        }
        else if(r==1){ //only one add
            for(int i=1;i<=3;i++) if(a[i]%2) cout<<a[i]<<endl;
            for(int tmp,i=4;i<=n;i++) cin>>tmp;
        }
        else if(r==2){ //only one even
            for(int i=1;i<=3;i++) if(a[i]%2==0) cout<<a[i]<<endl;
            for(int tmp,i=4;i<=n;i++) cin>>tmp;
        }
        else{//all odd
            for(int tmp,i=4;i<=n;i++){
                cin>>tmp;
                if(tmp%2==0) cout<<tmp<<endl;
            }
        }
    }
    return 0;
}
