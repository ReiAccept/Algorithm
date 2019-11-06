#include<cstdio>
#include<iostream>

using namespace std;

int q,a,b,n,s;

int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d",&a,&b,&n,&s);
        int yu=s%n,t=s/n;
        if(yu>b) 
        {
            cout<<"NO"<<endl; continue;
        }
        if(a*n+b < s)
        {
            cout<<"NO"<<endl; continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}
