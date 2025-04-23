#include<iostream>

using namespace std;

int M;
int feb[1000003]={0,1,1};

int main()
{
    cin>>M;
    for(int i=3;i<=1000002;i++) feb[i]=(feb[i-1]+feb[i-2])%M;
    for(int i=2;i<=1000002;i++)
    {
        //cout<<feb[i-1]%M<<" "<<feb[i-2]%M<<endl;
        if(!(feb[i]%M) && feb[i+1]%M==1)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
