#include <iostream>

using namespace std;

int main()
{
    int n,k,max,min;
    max=min=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        cin>>k;
        if(max==min && max==0)
            max=min=k;
        if(k<min)
            min=k;
        if(k>max)
            max=k;
    }
        cout<<min<<" "<<max<<endl;
        return 0;
}