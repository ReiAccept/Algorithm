#include<iostream>

using namespace std;

int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int a,b,c,ans=0;
        cin>>a>>b>>c;
        int a1=a,b1=b,c1=c/2;
        if(c1<b1){
            ans+=c1*3;
            b1-=c1;
        }
        else ans+=b1*3;
        if(b1<=0) cout<<ans<<endl;
        else{
            b1>>=1;
            ans+=min(b1,a1)*3;
            cout<<ans<<endl;
        }
    }
    return 0;
}
