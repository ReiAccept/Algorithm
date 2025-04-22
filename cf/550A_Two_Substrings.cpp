#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

string s;
int cnt,spj;
bool vis[100003];

void work()
{
    cin>>s;
    for(int i=0;i<(int)s.size()-1;i++)
    {
        if(s[i]=='A' && s[i+1]=='B')
        {
            vis[i]=vis[i+1]=true;
            cnt++;
            break;
        }
    }
    for(int i=0;i<(int)s.size()-1;i++)
    {
        if(s[i]=='B' && s[i+1]=='A' && !vis[i] && !vis[i+1] && cnt)
        {
            printf("YES\n");
            return ;
        }
    }
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<(int)s.size()-1;i++)
    {
        if(s[i]=='B' && s[i+1]=='A')
        {
            vis[i]=vis[i+1]=true;
            cnt++;
            break;
        }
    }
    for(int i=0;i<(int)s.size()-1;i++)
    {
        if(s[i]=='A' && s[i+1]=='B' && !vis[i] && !vis[i+1] && cnt)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
    return; 
}

signed main()
{
    int Case = 1;//read();
	while(Case--) work();
    return 0;
}
