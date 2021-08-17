#include<cstdio>
#include<iostream>

using namespace std;

int ans,n;
string sx,s,l="love";
bool vis[200003];
bool flag=true;

int main()
{
    cin>>sx;
    for(int i=0;i<(int)sx.size();i++)
    {
        if(sx[i]=='l' || sx[i]=='o' || sx[i]=='v' || sx[i]=='e')
            s+=sx[i];
    }
    n=(int)s.size();
    for(int i=n-1;flag && i>=0;i--)
    {
        if(vis[i]) continue;
        vis[i]=true;
        if(s[i]=='e')
        {
            int cur=2;
            for(int j=i-1;j>=0;j--)
            {
                if(s[j]==l[cur] && !vis[j])
                {
                    cur--;
                    vis[j]=true;
                    if(cur<0)
                    {
                        ans++;
                        break;
                    }
                }
                if(j==0 && cur>=0)flag=false;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

