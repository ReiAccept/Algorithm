#include<iostream>

using namespace std;

int n;
string s;

int main()
{
    cin>>n>>s;
    for(int i=2; i<=n; i++)
    {
        string ss;
        cin>>ss;
        long unsigned int x=s.find(ss[0]);
        s.erase(x,1);//清除根节点
        s.insert(x,ss);
    }
    for(int unsigned i=0; i<s.size(); i++) if(s[i]!='*') cout<<s[i];
}
