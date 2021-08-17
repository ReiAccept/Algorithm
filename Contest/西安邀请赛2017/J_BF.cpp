#include<bits/stdc++.h>
#define int long long

using namespace std;
const int mod = 1e9+7;
const int xi_shu=531192758;
char s[6][103];

signed main()
{
    while(cin>>(s[1]+1)>>(s[2]+1)>>(s[3]+1)>>(s[4]+1)>>(s[5]+1))
    {
        int len=0,ans=0;
        for(int i=1;i<=100;i++) if(s[5][i]=='1') len++;
        for(int i=1;i<=100;i++)
        {
            if(s[1][i]=='0') continue;
            for(int j=1;j<=100;j++)
            {
                if(s[2][i]=='0' || i==j)continue;
                for(int k=1;k<=100;k++)
                {
                    if(s[3][i]=='0' || k==i || k==j) continue;
                    for(int l=1;l<=100;l++)
                    {
                        if(s[4][i]=='0' || l==i || l==j || l==k) continue;
                        int res=len;
                        if(s[5][i]=='1') res--;
                        if(s[5][j]=='1') res--;
                        if(s[5][k]=='1') res--;
                        if(s[5][l]=='1') res--;
                        if(res>0) ans=(ans+res)%mod;
                    }
                }
            }
        }
        cout<<(ans*xi_shu)%mod<<endl;;
    }
    return 0;
}