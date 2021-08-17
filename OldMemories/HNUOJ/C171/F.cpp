#include<iostream>

using namespace std;

int n,sum;
int a[1003];

int main()
{
    cin>>n;
    while(n--)
    {
        int tmp;
        cin>>tmp;
        a[tmp]++;
    }
    for(int i=0;i<=1002;i++)
        if(a[i])
            sum++;
    cout<<sum<<endl;
    sum--;
    for(int i=1002;i>=0;i--)
        if(a[i])
        {
            if(sum)
            {
                cout<<i<<" ";
                sum--;
            }
            else
                cout<<i;
        }
    return 0;
}
