#include<bits/stdc++.h>
#define int long long

using namespace std;

string s;
int n,m,ans;
const int MOD=19260817;
stack<int> st;

signed main()
{
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        if(s[i]=='(') st.push(0);
        else
        {
            int ret=st.top();
            st.pop();
            if(ret==0)
            {
                if(!st.empty()) st.top()++;
                else ans=(ans+1)%MOD;
            }
            else
            {
                if(!st.empty()) st.top()=(ret*n+st.top())%MOD;
                else ans=(ans+ret*n)%MOD;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
