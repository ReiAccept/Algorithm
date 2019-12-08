#include<iostream>

using namespace std;

int n,ans;
string  begc;
int used[23];
string str[23];

bool checkstr(string a,string b,int len)
{
    for(int i=0;i<len;i++) if(a[a.size()-len+i]!=b[i]) return false;
    return true;
}

void dfs(string now)
{
    ans=max(ans,(int)now.size());
    for(int i=1;i<=n;i++)
    {
        if(used[i]>=2) continue;
        for(unsigned int j=1;j<str[i].size();j++)
            if(checkstr(now,str[i],j))
            {
                string tmp=now;
                for(unsigned int k=j;k<str[i].size();k++) tmp+=str[i][k];
                if(tmp==now) continue;
                used[i]++;
                dfs(tmp);
                used[i]--;
            }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>str[i];
    cin>>begc;
    dfs(begc);
    cout<<ans<<endl;
    return 0;
}
