#include<iostream>

using namespace std;

int n,b,a;
int map[10000010];

int main()
{
    cin>>n>>b>>a;
    for(int i=1; i<=n; i++) cin>>map[i];
    int i=0;
    int b1=b,a1=a;
    while((a1 || b1) && i++ <=n)
    {
        if(map[i]==0)
        {
            if(a1) a1--;
            else b1--;
        }
        if(map[i]==1)
        {
            if(b1 && a1<a) b1--,a1++;
            else a1--;
        }
        if(i==n) break;
    }
    cout<<i<<endl;
}
