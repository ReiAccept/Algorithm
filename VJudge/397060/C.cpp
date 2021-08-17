#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

string s;

void Solve()
{
    int sum=0,ans=0;
    qrd();
    cin>>s;
    for(unsigned int i=0;i<s.size();i++)
    {
        if(s[i]=='(')sum++;
        else if(s[i]==')')sum--;
        if(sum<0)
        {
            ans++;
            sum=0;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
