#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
int cnt[200005];
string s;

void Solve()
{
    n=qrd();
    cin>>s;
    priority_queue<int,vector<int>,greater<int> > p,q;
    int k=1;cnt[0]=1;
    if(s[0]=='0') q.push(1);
    else p.push(1);
    for(int i=1;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(p.empty())
            {
                q.push(++k);
                cnt[i]=k;
            }
            else
            {
                cnt[i]=p.top();
                p.pop();
                q.push(cnt[i]);
            }
        }
        else
        {
            if(q.empty())
            {
                p.push(++k);
                cnt[i]=k;
            }
            else
            {
                cnt[i]=q.top();
                q.pop();
                p.push(cnt[i]);
            }
        }
    }
    printf("%d\n",k);
    for(int i=0;i<n;i++) printf("%d ",cnt[i]);
    printf("\n");
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
