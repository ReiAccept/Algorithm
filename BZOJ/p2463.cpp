#include<iostream>

using namespace std;

int n;

int main()
{
    while(cin>>n){
        if(n==0) break;
        if(n%2==0) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
