#include<cstdio>
#include<iostream>

using namespace std;

string a,b;
int t1[30],t2[30];

int main()
{
    cin>>a>>b;
    if(a==b)
    {
        cout<<"Equal"<<endl;
        return 0;
    }
    if(a.size()!=b.size() || a[0]!=b[0] || a[a.size()-1]!=b[b.size()-1])
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<a.size();i++)
    {
        t1[a[i]-'a']++;
        t2[b[i]-'a']++;
    }
    for(int i=0;i<=27;i++)
    {
        if(t1[i]!=t2[i])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
