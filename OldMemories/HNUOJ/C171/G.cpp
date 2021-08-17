#include<iostream>
#include<algorithm>

using namespace std;

int a[13],b[13];
int ax,bx;

int main()
{
    for(int i=1;i<=10;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp%2==0)
            a[ax++]=tmp;
        else
            b[bx++]=tmp;
    }
    sort(a,a+ax);
    sort(b,b+bx);
    for(int i=bx-1;i>=0;i--)
        cout<<b[i]<<" ";
    for(int i=0;i<ax;i++)
        if(i==ax-1)
        {
            cout<<a[i];
        }
        else
        {
            cout<<a[i]<<" ";
        }
    return 0;
} 
