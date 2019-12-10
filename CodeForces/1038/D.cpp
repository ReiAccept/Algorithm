#include<iostream>
#include<algorithm>

using namespace std;

int n,num;
long long sum,minn=99999999999999999;

int main()
{
    cin>>n;
    if(n==1)
    {
        cin>>num;
        cout<<num<<endl;
    }
    else
    {
        int dayu0=0,xiaoyu0=0;
        for(int i=1; i<=n; i++)
        {
            cin>>num;
            if(num>0) dayu0++;
            if(num<0) xiaoyu0++;
            sum+=(long long)abs(num);
            minn=min(minn,(long long)abs(num));
        }
        if(dayu0>0 && xiaoyu0>0) cout<<sum<<endl;//假如有正有负,答案是所有数绝对值的和
        else cout<<sum-minn*2<<endl;//假如全正全负,答案是所有数绝对值的和-(所有数中绝对值最小的数*2)
    }
    return 0;
}
