#include<iostream>

using namespace std;

int T,r,g,b,w;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>r>>g>>b>>w;
        int cnt2,cnt=(r&1)+(g&1)+(b&1)+(w&1);
        if(r>0 && g>0 && b>0)cnt2=((r-1)&1)+((g-1)&1)+((b-1)&1)+((w+3)&1);
        else cnt2=2;
        if(cnt<=1 || cnt2<=1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
