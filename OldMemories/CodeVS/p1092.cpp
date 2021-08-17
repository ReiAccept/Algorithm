#include <iostream>

using namespace std;

int main()
{
    int a,b,val,maxs,maxday=0;
    for(int i=1;i<=7;i++)
    {
        cin>>a>>b;
        val=a+b;
        if(i==1)
        {
            maxs=val;
            continue;
        }
        if(val<=8)
            continue;
        if(maxs<val)
            maxday=i;
        maxs=max(maxs,val);
    }
    cout<<maxday<<endl;
    return 0;
}