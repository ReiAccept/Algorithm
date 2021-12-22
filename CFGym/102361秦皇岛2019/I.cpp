#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+3;
const int INF=0x3f3f3f3f;

int n;
char ss[MAXN];
char cache[10];
int dp[MAXN][7];
map<char,int> mp,m;
int num[15];
string s[15][10];
int ans=INF;

void INIT() {
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=6;j++) {
            dp[i][j]=INF;
        }
    }
    //mp['Y']="QQQ"; mp['V']="QQW"; mp['G']="QQE"; mp['X']="QWW"; mp['F']="QEE"; mp['B']="QWE";
    //mp['C']="WWW"; mp['Z']="WWE"; mp['D']="WEE";
    //mp['T']="EEE";
    mp['Y']=1; mp['V']=2; mp['G']=3; mp['X']=5; mp['F']=8; mp['B']=10;
    mp['C']=4; mp['Z']=6; mp['D']=9;
    mp['T']=7;
    num[1]=num[4]=num[7]=1;
    num[2]=num[3]=num[5]=num[6]=num[8]=num[9]=3;
    num[10]=6;
    s[1][1]="QQQ";
    s[2][1]="QQW"; s[2][2]="WQQ"; s[2][3]="QWQ";
    s[3][1]="QQE"; s[3][2]="EQQ"; s[3][3]="QEQ";
    s[4][1]="WWW";
    s[5][1]="QWW"; s[5][2]="WWQ"; s[5][3]="WQW";
    s[6][1]="WWE"; s[6][2]="EWW"; s[6][3]="WEW";
    s[7][1]="EEE";
    s[8][1]="QEE"; s[8][2]="EEQ"; s[8][3]="EQE";
    s[9][1]="WEE"; s[9][2]="EEW"; s[9][3]="EWE";
    s[10][1]="QWE"; s[10][2]="QEW"; s[10][3]="WQE"; s[10][4]="WEQ"; s[10][5]="EQW"; s[10][6]="EWQ";
}

signed main()
{
    scanf("%s",ss+1);
    n=strlen(ss+1);
    INIT();
    for(int i=1;i<=num[mp[ss[1]]];i++)dp[1][i]=3;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=num[mp[ss[i]]];j++)
        {
            for(int k=1;k<=num[mp[ss[i-1]]];k++)
            {
                int x;
                string s1=s[mp[ss[i-1]]][k],s2=s[mp[ss[i]]][j];
                if(s1==s2)x=0;
                else if(s1[1]==s2[0]&&s1[2]==s2[1])x=1;
                else if(s1[2]==s2[0])x=2;
                else x=3;
                dp[i][j]=min(dp[i-1][k]+x,dp[i][j]);
            }
        }
    }
    for(int i=1;i<=num[mp[ss[n]]];i++)ans=min(ans,dp[n][i]);
    ans+=n;
    printf("%d\n",ans);
    return 0;
}