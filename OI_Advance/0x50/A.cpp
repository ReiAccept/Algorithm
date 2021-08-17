#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int n;
int s[6];

void work()
{
    while(n=read())
    {
        mmst0(s);
        for(int i=1;i<=n;i++) s[i]=read();
        int f[s[1]+1][s[2]+1][s[3]+1][s[4]+1][s[5]+1];
        mmst0(f);
        f[0][0][0][0][0]=1;
        for(int i=0;i<=s[1];i++)
        {
            for(int j=0;j<=s[2];j++)
            {
                for(int k=0;k<=s[3];k++)
                {
                    for(int l=0;l<=s[4];l++)
                    {
                        for(int m=0;m<=s[5];m++)
                        {
                            if(i<s[1]) f[i+1][j][k][l][m]+=f[i][j][k][l][m];
                            if(j<s[2] && j<i) f[i][j+1][k][l][m]+=f[i][j][k][l][m];
                            if(k<s[3] && k<j) f[i][j][k+1][l][m]+=f[i][j][k][l][m];
                            if(l<s[4] && l<k) f[i][j][k][l+1][m]+=f[i][j][k][l][m];
                            if(m<s[5] && m<l) f[i][j][k][l][m+1]+=f[i][j][k][l][m];
                        }
                    }
                }
            }
        }
        cout<<f[s[1]][s[2]][s[3]][s[4]][s[5]]<<endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
