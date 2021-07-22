#include<bits/stdc++.h>
//#define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double rld;
typedef unsigned long long ull;

const rld eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f;//LLINF
const int MAXN=(int)1e5+3;

int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
//void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

void work()
{
    char s1[12],s2[12],s[3010];
    map<string,string>word;
    scanf("%s",s1);
    while(scanf("%s",s1),strcmp(s1,"END"))
    {
        scanf("%s",s2);
        word.insert(pair<string,string>(s2,s1));
    }
    scanf("%s",s1);
    getchar();
    while(gets(s),strcmp(s,"END"))
    {
        for(int i=0,j=0;i<(int)strlen(s);i++)
        {
            if(isalpha(s[i])) s1[j++]=s[i];
            if(!isalpha(s[i])&&j!=0)
            {
                s1[j]='\0';
                j=0;
                if(word.find(s1) != word.end()) cout<<word[s1];
                else printf("%s",s1);
            }
            if(!isalpha(s[i])) printf("%c",s[i]);
        }
        printf("\n");
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        //while(cin>>n)
        work();
    }
    return 0;
}
