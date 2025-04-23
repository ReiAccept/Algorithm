#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long

using namespace std;
using namespace __gnu_pbds;

tree<ll,null_type, less<ll> ,rb_tree_tag,tree_order_statistics_node_update> T;
ll n,oper,x,ans=-1e9;

int main() 
{
    cin>>n;
    for(ll i=1;i<=n;ans=-1e9,i++)
    {
        cin>>oper>>x;
        if(oper==1) T.insert((x<<20)+i);
        if(oper==2) T.erase(T.lower_bound(x<<20));
        if(oper==3) cout<<T.order_of_key(x<<20)+1<<endl;
        if(oper==4) ans = *T.find_by_order(x-1);
        if(oper==5) ans = *--T.lower_bound(x<<20);
        if(oper==6) ans = *T.lower_bound((x+1)<<20);
        if(ans!=-1e9) cout<<(ans>>20)<<endl;
    }
    return 0;
}
