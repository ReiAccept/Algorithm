#include <iostream>
#include <string>

using namespace std;

int main()
{
    string v1,v2;
    int sz1,sz2,n;
    cin>>v1>>v2;
    sz1=v1.length();
    sz2=v2.length();
    
    for(int i=0;i<sz1;i++)
    {   
        int t=i;
        n=0;
        for(int k=0;k<sz2;k++)
        {
            if(v2[k]!=v1[t])
                break;
            t++;
            n++;
            if(n==sz2)
            {
                cout<<++i<<endl;
                return 0;
            };
        }
    }
}