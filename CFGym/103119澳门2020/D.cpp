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

double atk=1500,cr=0.05,cdr=0.5;
string s;

double s2d(int cur)
{
    double res=0.0;
    int ptx=-1;
    for(int i=cur;i<s.size();i++)
    {
        if(s[i]=='%')break;
        else if(s[i]=='.') ptx=i;
        else if(ptx==-1)
        {
            res=res*10+(s[i]-'0');
        }
        else if(ptx!=-1)
        {
            //cout<<"RES:"<<res<<endl;
            double u=(double)(s[i]-'0');
            if(i-ptx==1) res+=u/10.0;
            else if(i-ptx==2) res+=u/100.0;
            else res+=u/pow(10.0,i-ptx);
        }
    }
    //res-=eps;
    //printf("%.2f\n",res);
    return res;
}

void work()
{
    for(int f1=1;f1<=5;f1++)
    {
        for(int f2=1;f2<=5;f2++)
        {
            getline(cin,s);
            if(!(s[0]=='A' || s[0]=='C')) continue;
            int cur=0; while(cur<s.size() && s[cur]!='0' && s[cur]!='1' && s[cur]!='2' && s[cur]!='3' && s[cur]!='4' && s[cur]!='5' && s[cur]!='6' && s[cur]!='7' && s[cur]!='8' && s[cur]!='9' && s[cur]!='0')cur++;
            if(cur==4) //ATK+
            {
                atk+=s2d(cur);
            }
            else if(cur==9) //ATK Rate+
            {
                atk=1500.0*(s2d(cur)/100.0)+atk;
            }
            else if(cur==10) //Crit Rate+
            {
                cr+=(s2d(cur)/100.0);
            }
            else if(cur==14)//Crit DMG Rate+
            {
                cdr+=(s2d(cur)/100.0);
            }
        }
    }
    if(cr>=1.0)printf("%.6lf\n",atk*(1+cdr));//cout<<0<<endl;
    else printf("%.6lf\n",atk*(1.0-cr)+atk*(1+cdr)*cr);//cout<<atk*(1.0-cr)+atk*(1+cdr)*cr<<endl;
    //cout<<e<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(int)read();
    for(signed Case=1; Case<=T; Case++)
    {
        //printf("Case %d: ",Case);
        work();
    }
    return 0;
}