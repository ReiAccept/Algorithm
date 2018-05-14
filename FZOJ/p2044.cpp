#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

int a,n,k,ans;
map <int,bool> m;
map <int,bool> :: iterator it;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&a);
        it = m.find(a);
        if(it == m.end() )
        {
            m.insert( pair<int,bool>(a,1) );
            ans++;
        }
    }
    if(n-k<ans)ans=n-k;
    printf("%d",ans);
    return 0;
}
