#include<cstdio>
#include<iostream>

using namespace std;

int n,t;
double a[30],b[30];

int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    a[2]=b[1]=1;b[2]=2;
    for(int i=3;i<=20;i++)
    {
        a[i] = (i-1)*(a[i-1]+a[i-2]);
        b[i] = b[i-1]*i;
    }
    while(t--)
    {
        cin>>n;
        printf("%.2lf%%\n",(a[n]/b[n]*100));
    }
}
