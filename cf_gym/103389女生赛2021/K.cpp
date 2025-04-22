#include<bits/stdc++.h>

using namespace std;

int n,ans;
char s[10];

signed main()
{
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++) {
        gets(s);
        for(int i=1;i<=5;i++) {
            if(s[i]!=' ' && s[i]!='|') ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}