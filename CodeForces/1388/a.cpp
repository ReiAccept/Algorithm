#include <iostream>

using namespace std;

int n,T;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n<=30)cout<<"NO"<<endl;
        else if(n==36) cout<<"YES"<<endl<<"6 14 15 1"<<endl;
        else if(n==40) cout<<"YES"<<endl<<"6 14 15 5"<<endl;
        else if(n==44) cout<<"YES"<<endl<<"6 14 15 9"<<endl;
        else cout<<"YES"<<endl<<"6 10 14 "<<n-30<<endl;
    }
    return 0;
}

