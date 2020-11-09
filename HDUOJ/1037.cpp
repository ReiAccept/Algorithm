#include <iostream>

using namespace std;

int n,m,k;

int main()
{
    while(cin>>n>>m>>k)
    {
        if(n<=168) cout << "CRASH "<<n<< endl;
        else if(m<=168) cout << "CRASH "<<m<< endl;
        else if(k<=168) cout << "CRASH "<<k<< endl;
        else cout<<"NO CRASH"<<endl;
    }
    return 0;
}
