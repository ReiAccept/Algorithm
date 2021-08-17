#include<cstdio>
#include<iostream>

using namespace std;

int n,l;
int res[20];

int main()
{    
    while(cin>>n)
    {
        l=0;
        while(n)
        {
            res[l]=n%2+'0';
            l++;
            n>>=1;
        }
        for(int i=l-1;i>=0;i--) printf("%c",res[i]);
        cout<<endl;
    } 
    return 0;
}
