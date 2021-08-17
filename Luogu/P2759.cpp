#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

int n,l=1,r=2000000000;

int main()
{
    cin>>n;
    while(l<r)
    {
        int m=(l+r)>>1;
        long long len=(long long)(m*log10(m))+1;
        if(len<n) l=m+1;
        else r=m;
    }
    cout<<l<<endl;
    return 0;
}
/*
求数x的位数的方法：
x的位数=log10(x)+1;取整
log10(double)是cmath头文件里自带的10为底的对数
题目的数很大时利用对数运算，把指数提出来，作为系数
即log(x^x)=x*log(x)
*/
