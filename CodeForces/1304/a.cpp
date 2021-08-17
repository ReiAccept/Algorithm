#include<iostream>

using namespace std;

long long t,x,y,a,b;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>a>>b;
        if((y-x)%(a+b)) cout<<"-1"<<endl;
        else cout<<(y-x)/(a+b)<<endl;
    }
    return 0;
}
