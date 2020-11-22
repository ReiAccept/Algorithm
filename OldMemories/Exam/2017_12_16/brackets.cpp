#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int t,n;
char s[5001];
char a[5001];

bool check()
{
    bool flag_t=true;
    for(int i=1; i<=n; i++)
        if(a[i]==a[n-i+1])
        {
            flag_t=false;
            break;
        }
    return flag_t;
}

void fanzhuan(int x,int y)
{
    for(int i=x; i<=y; i++)
    {
        if(a[i]=='(')
            a[i]=')';
        else if(a[i]==')')
            a[i]='(';
    }
}

int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    cin>>t;
    while(t--)
    {
        bool flagx=true;
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        cin>>s;
        n=strlen(s);
        for(int i=0; i<n; i++)
            a[i+1]=s[i];
        for(int i=1; i<=n && flagx; i++)
        {
            for(int j=n; j>i; j--)
            {
                fanzhuan(i,j);
                if(check())
                {
                    printf("possible\n");
                    flagx=false;
                    break;
                }
                fanzhuan(i,j);
            }
        }
        if(flagx)
            printf("impossible\n");
    }
    return 0;
}
