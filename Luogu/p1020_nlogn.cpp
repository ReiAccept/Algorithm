#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,cur1=1,cur2=1;
int h[100003],f1[100003],f2[100003];

int main()
{
    while(cin>>h[++n]);
    n--;
    f1[1]=f2[1]=h[1];
    for(int i=2;i<=n;i++)
    {
        if(hh[i]<=f1[cur1])f1[++cur1]=h[i];
        else *upper_bound(f1+1,f1+cur1+1,h[i],greater<int>())=h[i];//这里换lowerbound不行,但是我草稿中并没有手动模拟出为什么换成lowerbound不行
        if(h[i]>f2[cur2])f2[++cur2]=h[i];
        else *lower_bound(f2+1,f2+cur2+1,h[i])=h[i];
    }
    cout<<cur1<<endl<<cur2<<endl;
    return 0;
}
//Dilworth定理：偏序集的最少反链划分数等于最长链的长度
//lower_bound会找出序列中第一个大于等于x的数的指针地址
//upper_bound会找出序列中第一个大于x的数的指针地址
//greater<int>()就是c++提供的大于函数
