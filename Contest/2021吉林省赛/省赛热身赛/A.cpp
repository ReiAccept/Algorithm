#include<bits/stdc++.h>
#define int long long

using namespace std;
//4294967295->4294967296
//1638180132
signed main() {
    // cout<<time(NULL)<<endl;
    // cout<<4077<<endl;
    int years=(365*3+366)*24*60*60;
    
    cout<<1970 + (4294967295*4/years)<<endl;
    return 0;
}