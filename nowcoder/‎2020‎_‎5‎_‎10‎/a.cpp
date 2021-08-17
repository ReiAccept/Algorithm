#include<iostream>

using namespace std;

int T;

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(((n/gcd(a,b)))%2==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
