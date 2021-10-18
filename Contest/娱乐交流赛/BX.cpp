#include<bits/stdc++.h>

using namespace std;

int ans;
string s;

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)    
    {
        int tot=0,n=0; 
        for(int j=i;j<s.size();j++)
        {
            if(s[j]=='(') tot++;
            if(s[j]==')') tot--;
            if(s[j]=='?')
            {
                if(tot>0) tot--,n++;
                else tot++;
            } 
            if(tot<0 && n) tot+=2,n--;
            if(tot<0 && !n) break; 
            if(!tot) ans++; 
        }    
    }
    printf("%d\n",ans);
    return 0;
}

