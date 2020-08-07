#include<cstdio>
#include<iostream>

using namespace std;

char op;
int n,q,x,le,cnt2,cnt4;
int a[100003];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>le;
        a[le]++;
        if(!(a[le]%2))cnt2++;
        if(!(a[le]%4))cnt4++;
    }
    cin>>q;
    while(q--)
    {
        cin>>op>>x;
        if(op=='+')
        {
            a[x]++;
            if(!(a[x]%2))cnt2++;
            if(!(a[x]%4))cnt4++;
        }
        else
        {
            if(!(a[x]%2))cnt2--;
            if(!(a[x]%4))cnt4--;
            a[x]--;
        }
        if(cnt2>=4 && cnt4>0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
