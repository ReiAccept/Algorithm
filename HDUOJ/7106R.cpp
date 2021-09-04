#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+4;
int A,B,C,D,n,T;
vector<int> v[55];
int get(int x)
{
    int res = 0;
    while(x){
        res+=x%10; 
        x/=10;
    }
    return res;
}
void init(){
    for(int i=1;i<=maxn;i++) v[get(i)].push_back(i);
}
int cal(int x){
    int g=get(x);
    return A * x * x * g + B * x * x + C*x*g*g + D * x*g;
}
signed main()
{
    init();
    cin>>T;
    while(T--)
    {
        int ans = INT_MAX;
        cin>>A>>B>>C>>D>>n;
        ans = min(ans,cal(1));
        //cout<<ans<<endl;
        ans = min(ans,cal(n));
        //cout<<ans<<endl;
        for(int i=1;i<=54;i++)
        {
            int pos = upper_bound(v[i].begin(),v[i].end(),n) - v[i].begin();
            if(pos!=0) ans = min(ans,cal(v[i][pos-1]));
            //cout<<ans<<endl;
            if(v[i].size() && n >= v[i][0]) ans = min(ans,cal(v[i][0]));
            //cout<<ans<<endl;
            if(A*i+B==0) continue;
            int x = -(C*i*i+D*i)/(A*i+B)/2;
            if(x>=1)//不是单调的
            {
                pos = lower_bound(v[i].begin(),v[i].end(),x) - v[i].begin();
                if( n >= x ) {
                    if(pos!=v[i].size() && v[i][pos]<=n) ans = min(ans,cal(v[i][pos]));
                    if(pos!=0&&v[i][pos]<=n) ans = min(ans,cal(v[i][pos-1]));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
