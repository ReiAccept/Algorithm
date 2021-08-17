#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int t,s,f;
string m,s1,s2;

void work()
{
    scanf("%d:%d",&s,&f);
    cin>>m>>s1>>s2;
    if(m[0]=='A'&&s==12) s=0;
    else if(m[0]=='P'&&s!=12) s+=12;
    if(s1=="Moscow") s-=3;
    else if(s1=="Beijing") s-=8;
    else if(s1=="Washington") s+=5;
    if(s2=="Moscow") s+=3;
    else if(s2=="Beijing") s+=8;
    else if(s2=="Washington") s-=5;
    if(s<0)
    {
        printf("Yesterday ");
        s+=24;
    }
    else if(s>=24)
    {
        printf("Tomorrow ");
        s-=24;
    }
    else printf("Today ");
    if(s==0) printf("12:%02d AM\n",f);
    else if(s>=1&&s<12) printf("%d:%02d AM\n",s,f);
    else if(s==12) printf("12:%02d PM\n",f);
    else printf("%d:%02d PM\n",s-12,f);

    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=read();
    for(int Case=1; Case<=T; Case++)
    {
        printf("Case %d: ",Case);
        work();
    }
    return 0;
}
