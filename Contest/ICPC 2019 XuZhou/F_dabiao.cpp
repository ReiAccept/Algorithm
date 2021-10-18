#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
typedef long long ll;
tr1::unordered_map<ll,int> f;

ll g(ll x)
{
    for(ll i=-5000; i<=5000; i++)
        if (i*i*i==x) return i;

}

bool find(int x)
{
    for(ll i =0; i<=5000; i++)
        for(long long j=0; j<=5000; j++)
            if (f.count(i*i*i+j*j*j+x))
            {
                printf("a[%d] = %lld;\n",x,g(i*i*i+j*j*j+x));
                printf("b[%d] = %lld;\n",x,-i);
                printf("c[%d] = %lld;\n",x,-j);
                return true;
            }
            else if (f.count(i*i*i+j*j*j-x))
            {
                //printf("%lld %lld %lld = %d\n",i,j,-g(i*i*i+j*j*j-x),x);
                printf("a[%d] = %lld;\n",x,g(i*i*i+j*j*j-x)==0?0:-g(i*i*i+j*j*j-x));
                printf("b[%d] = %lld;\n",x,i);
                printf("c[%d] = %lld;\n",x,j);
                return true;
            }
    return false;
}

int main()
{
    freopen("ans.cpp","w",stdout);
    f.clear();
    for(ll i=-5000; i<=5000; i++)
        f[i*i*i] = 1;
    for(int x=0; x<=200; x++)
    {
        //printf("find %d\n",x );
        if (find(x))
        {
            printf("vis[%d] = true;\n",x);
        }
        else
            printf("vis[%d] = false;\n",x);
    }
    return 0;
}


