#include<iostream>

using namespace std;

int T,a,b,m;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>m>>a>>b;
        if(m>6) a=(m-6)*8+27+a;
        else a=(15-m)*m/2 + a;
        if(a>=b) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
