#include<iostream>

using namespace std;

int T,r,g,b,w;

bool check(int r,int g,int b,int w)
{
    int k=0;
    if(r%2)k++;
    if(g%2)k++;
    if(b%2)k++;
    if(w%2)k++;
    if(k>1)return false;
    return true;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>r>>g>>b>>w;
        if(check(r,g,b,w) || check(r-1,g-1,b-1,w+3))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
