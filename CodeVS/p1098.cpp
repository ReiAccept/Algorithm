#include <iostream>

using namespace std;

int main()
{
    int n,pj=0,flag=0;
    cin>>n;
    int card[n];
    for(int i=0;i<n;i++)
    {
        cin>>card[i];
        pj+=card[i];
    }
    pj/=n;
    for(int i=0;i<n-1;i++)
        if(card[i]!=pj)
        {
            card[i+1]+=card[i]-pj;
            flag++;
        }
    cout<<flag<<endl;
    return 0;
}