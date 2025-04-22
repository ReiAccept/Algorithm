#include <iostream>
using namespace std;

int main()
{
    char a[100009],b;
    int l=0,r=0,num=0,i=0;
    while(cin>>b)
    {
        if(b=='E')
            break;
        a[i++]=b;
    }
    for(int j=0; j<i; j++)
    {
        if(a[j]=='W')l++;
        if(a[j]=='L')r++;
        num++;
        if((l>=11||r>=11)&&(l-r>=2||r-l>=2))
        {
            cout<<l<<":"<<r<<endl;
            l=0;
            r=0;
            num=0;
        }
    }
    cout<<l<<":"<<r<<endl;
    l=0;
    r=0;
    cout<<endl;
    for(int j=0; j<i; j++)
    {
        if(a[j]=='W')l++;
        if(a[j]=='L')r++;
        num++;
        if((l>=21||r>=21)&&(l-r>=2||r-l>=2))
        {
            cout<<l<<":"<<r<<endl;
            l=0;
            r=0;
            num=0;
        }
    }
    cout<<l<<":"<<r<<endl;
    return 0;
}
