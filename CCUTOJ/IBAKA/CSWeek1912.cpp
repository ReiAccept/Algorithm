#include<bits/stdc++.h>

using namespace std;

int n,q,r;
string s,str;
int w[30];

int main()
{
    cin>>n>>str>>q;
    while(q--)
    {
        cin>>s;
        memset(w,0,sizeof(w));
        for(unsigned i=0;i<s.size();i++) w[s[i]-'a']++;
        for(int i=0;i<30;i++) if(w[i])r++;
        for(unsigned i=0;i<str.size();i++)
        {
            if(w[str[i]-'a']>0)
            {
                w[str[i]-'a']--;
                if(w[str[i]-'a']==0)r--;
            }
            if(!r)
            {
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}
