#include<iostream>

using namespace std;

int n;
long long ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) ans+=(n/i);
    cout<<ans<<endl;
    return 0;
}

//对每个数i在1到n的范围内有n/i个数是他的倍数 答案就是∑(n/i)
