#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e4+3;
const int INF=0x3f3f3f3f3f3f3f3f;

int a,b,k;

signed main() {
    scanf("%lld%lld%lld",&a,&b,&k);
    if(a==b){
        printf("1.");
        for(int i=1;i<=k;i++)printf("0");
        return 0;
    }
    printf("0.");
    for(int i=1;i<=k-1;i++) {
        a*=10;
        printf("%lld",a/b);
        a%=b;
    }
    a*=10;
    int x1=a/b;
    a%=b;
    a*=10;
    int x2=a/b;
    if(x2>=5&&x2<=9)x1+=1;
    printf("%lld",x1);
    return 0;
}