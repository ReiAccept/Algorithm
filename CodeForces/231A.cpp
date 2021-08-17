#include<iostream>

using namespace std;

int n,ans;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ol,q=0;
        for(int i=1;i<=3;i++)
        {
            cin>>ol;
            if(ol)
            {
                q++;
            }
        }
        if(q>=2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
