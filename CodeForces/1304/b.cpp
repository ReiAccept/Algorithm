#include<iostream>
#include<algorithm>

using namespace std;

int n,m,ans;

bool flag;
bool vis[103];
string str,strq;
string s[103],sr[103];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++)
    {
        sr[i]=s[i];
        reverse(sr[i].begin(),sr[i].end());
    }
    for(int i=1;i<=n;i++)
        for(int j=n;j>=i;j--)
            if(s[i]==sr[j] && !vis[j])
            {
                vis[j]=true;
                ans+=2;
                if(i!=j)str=s[i]+str;
                else if(!flag)
                {
                    strq=s[i];
                    ans--;
                    flag=true;
                }
                else ans-=2;
                break;
            }
    cout<<ans*m<<endl<<str<<strq;
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}
