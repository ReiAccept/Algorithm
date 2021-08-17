#include<climits>
#include<iostream>

using namespace std;

int n,k,js[100010]; 
long long sum[100010],a[100010],res;

int main()
{
    cin>>n>>k;
	for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        res+=a[i];
    }
    for(int i=0;i<k;++i)
        sum[i]=INT_MAX;
    for(int i=1;i<=n;++i)
    {
        js[i%k]++;
        if(a[i]<sum[i%k] && js[i%k]%2==1)
            sum[i%k]=a[i];
    }
    for(int i=0;i<k;++i)
    {
        if(js[i]%2==1)
        res-=sum[i];
    }
	cout<<res<<endl;
    return 0;
}
/*
将每个硬币的编号模k,分成k组,同一组之间的硬币是会冲突的(既拿了一部分,就可能会有一部分不能拿),不同组之间硬币是不会冲突的,这样问题就被简化了,我们再去考虑每一组,如果该组里面的硬币个数是偶数个，那么这一组的硬币都可以全部拿走,如果为奇数个的话,那么就会有一个无法拿走,在仔细分析,可以发现只可以将该组里第奇数个留下,(如果拿走第奇数个,那么前面拿走的就会是奇数个,不符合题意)
*/
