#include<bits/stdc++.h>

using namespace std;

int n;
string s;
int num[1003];

void add()
{
    int x=0;
    reverse(s.begin(),s.end());
    for(int i=0;i<(int)s.size();i++)
    {
        x+=s[i]-'0'+num[i];
        num[i]=(x%10);
        x/=10;
    }
    if(x)num[(int)s.size()]+=x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        memset(num,0,sizeof(num));
        while(cin>>s && s!="0")add();
        int len=1000;
        while(!num[len])len--;
        while(len>=0)
        {
            cout<<num[len];
            len--;
        }
        if(n>0) cout<<endl<<endl;
        else cout<<endl;
    }
    
}
