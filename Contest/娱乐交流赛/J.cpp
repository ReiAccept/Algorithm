#include<iostream>

using namespace std;

const double eps=0.00;

signed main()
{
    double x;
    while(cin>>x) {
        if(x==eps) break;
        int ans=0; double cnt=0;
        for(int i=2;cnt<x;i++) {
            cnt+=1.0/i;
            ans++;
        }
        cout<<ans<<" card(s)"<<endl;
    }
    return 0;
}

