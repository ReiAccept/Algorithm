#include<map>
#include<iostream>

using namespace std;

int n;
long long k;
long long a[100003];

bool f(int l, int r)
{
    if (l == r) return a[l]%k == 0;
    int mid = (l+r)/2;
    if (f(l, mid) || f(mid+1, r)) return true;
    map<long long, int> mp;
    long long sum = 0;
    for (int i=mid+1; i<=r; i++)
    {
        sum=(sum+a[i])%k;
        mp[sum]++;
    }
    sum = 0;
    for (int i=mid; i>=l; i--)
    {
        sum = (sum+a[i])%k;
        if (mp[(k-sum)%k]) return true;
    }
    return false;
}


int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    if(f(1,n))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
