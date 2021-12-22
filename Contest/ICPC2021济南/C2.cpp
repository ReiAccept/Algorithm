#include<bits/stdc++.h>
using namespace std;
int n,a[20],b[20];
int cnt,sum1,sum2,tot;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)sum1+=a[i];
        else sum2+=a[i];
    }
    sort(b+1,b+1+n);
    do
    {
        tot++;
        // bool flag=1;
        // for(int i=1;i<n;i++) {
        //     if(a[i]>a[i+1]) {
        //         flag=false;
        //         break;
        //     }
        // }
        // if(flag) cnt++;
        int cnt1=0,cnt2=0;
        bool f=false;
        for(int i=2;i<=n;i+=2)
        {
            if(a[b[i]]>a[b[i-1]])
            {
                f=true;
                break;
            }
        }
        if(!f)cnt++;
    } while (next_permutation(b+1,b+1+n));
    cout<<cnt<<endl;
    cout<<tot<<endl;
    return 0;
}