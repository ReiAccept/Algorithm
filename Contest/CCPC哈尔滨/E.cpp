#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 3;
const int INF=1e18;

int n,m;
bool flag;
int a[MAXN];

void work()
{
    flag=false; m=INF;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    if(a[1]!=1) {
        if(a[1]>1) {
            printf("-1\n");
            return;
        } else {
            m=1;
            flag=true;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] > (a[i - 1] * 2)%m) {
            printf("-1\n");
            return;
        }
        if(a[i] < (a[i - 1] * 2)%m) {
            if(m==INF){
                m=(a[i-1]*2-a[i])%m; //假了
                if((a[i-1]*2)%m!=a[i]){
                    printf("-1\n");
                    return;
                }
                flag=true;
            } else {
                printf("-1\n");
                return;
            }
        }
    }
    if(m==INF) {
        printf("-1\n");
        return;
    }
    printf("%lld\n",m);
}

signed main()
{
    int T;
    scanf("%lld", &T);
    for (int i = 0; i < T; i++)
    {
        work();
    }
}