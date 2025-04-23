#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

int a[1003];

int GCD(int a,int b)
{
    int temp;
    if(a < b)
        swap(a,b);
    if(a%b == 0)
        return b;
    else
        return GCD(b,a%b);
}

int LCM(int* a,int size_k)
{
    int x,y,num=a[0],i,gcd;
    for(i=0; (i+1)<size_k; i++)
    {
        x=num;
        y=a[i+1];
        gcd = GCD(x,y);
        num = x/gcd * y/gcd * gcd;
    }
    return num;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,result=INT_MAX;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n-k;i++)
            result=min(result,LCM(a+i,k));
        printf("%d\n",result);
    }
    return 0;
}
