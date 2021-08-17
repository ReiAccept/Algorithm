#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

string s;

void work()
{
    vector<char> a;
    for(int i=0;i<(int)s.size();i++)
    {
        a.push_back(s[i]);
        while(a.size()>=2)
        {
            int len=(int)a.size()-1;
            if(a[len]!=a[len-1]) break;
            if(a[len]=='O')
            {
                a.pop_back();
                a.pop_back();
            }
            else
            {
                a.pop_back();
                a.pop_back();
                a.push_back('O');
            }
        }
    }
    for(int i=0;i<(int)a.size();i++) printf("%c",a[i]);
    printf("\n");
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        while(cin>>s) work();
    }
    return 0;
}
