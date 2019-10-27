#include<iostream>

using namespace std;

int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int a,b,c,ans=0;
        cin>>a>>b>>c;
        while(b>=1 && c>=2)
        {
            ans+=3;
            b--;
            c-=2;
        }
        while(a>=1 && b>=2)
        {
            ans+=3;
            a--;
            b-=2;
        }
    cout<<ans<<endl;
    }
    return 0;
}
