#include <bits/stdc++.h>
using namespace std;
#define xx first
#define yy second
map<string, int> mp[23];
int n;
string s,t;
int main(){ 
    ios::sync_with_stdio(false);
    cin>>n>>s;
    mp[0][s] = 1;
    for(int i=1;i<=n;i++)
        for(auto it=mp[i-1].begin();it!=mp[i-1].end();++it)
        {
            t="";
            int len=(*it).xx.size();
            for(int i=0;i<len;i+=2) t+=(((*it).xx[i]-'0') | ((*it).xx[i+1]-'0'))+'0';
            mp[i][t]+=(*it).yy;
            t="";
            for(int i=0;i<len;i+=2) t+=(((*it).xx[i]-'0') & ((*it).xx[i + 1]-'0'))+'0';
            mp[i][t] += (*it).yy;
            t="";
            for(int i=0;i<len;i+=2) t+=(((*it).xx[i]-'0') ^ ((*it).xx[i + 1]-'0'))+'0';
            mp[i][t]+=(*it).yy;
        }
    cout<<mp[n]["1"]<<endl;
    return 0;
}
