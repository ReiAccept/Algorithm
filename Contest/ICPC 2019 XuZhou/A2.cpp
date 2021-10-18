#include<bits/stdc++.h>

using namespace std;

int s;

int chk(int l,int r,int res=0)
{
    if(l>r) return false;
    if(r-l+1 <=10) {
        for(int i=1;i<=r;i++) res^=i;
    } else {
        while(l%4!=0) {
            res^=l; l++;
        }
        while(r%4!=3) {
            res^=r; r--;
        }
    }
    return res<=s;
}

int l,r;

void work()
{
    scanf("%lld%lld%lld",&l,&r,&s);
    int res=-1;
    for(int i=0;i<=4;i++)
        for(int j=0;j<=4;j++) {
            if(chk(l+i,r-j)) res=max(res,(r-j)-(l+i)+1);
        }
    printf("%lld\n",res);
    return;
}

signed main()
{
    int T; scanf("%d",&T);
    for(int Case=1;Case<=T;Case++) work();
}
