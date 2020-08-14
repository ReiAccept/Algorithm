#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int n;
    bool f,vis;
} tmp,s[103];

bool flag;
int T,c,res,r,rx;
string str;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>str;
        res=0,r=1,c=1;
        memset(s,0,sizeof(s));
        for(unsigned i=1; i<str.size(); i++)
        {
            if(str[i]==str[i-1])c++;
            else
            {
                if(str[i-1]=='1')tmp.f=true;
                else tmp.f=false;
                tmp.n=c;
                s[r++]=tmp;
                c=1;
            }
        }
        if(str[str.size()-1]=='1')tmp.f=true;
        else tmp.f=false;
        tmp.n=c;
        s[r]=tmp;
        rx=r;
        flag=true;
        //for(int i=1;i<=r;i++)cout<<i<<" "<<s[i].n<<" "<<s[i].f<<endl;
        if(rx==1)
        {
            if(str[str.size()-1]=='1')res=str.size();
            else res=0;
        }
        else
        {
            while(rx>1)
            {
                int maxn=0,maxt=0;
                if(flag)
                {
                    for(int i=1; i<=r; i++)
                    {
                        if((!s[i].vis) && s[i].f && s[i].n>maxn)maxn=s[i].n,maxt=i;
                        //cout<<i<<" "<<s[i].n<<" "<<s[i].f<<endl;
                    }
                    res+=maxn;
                    s[maxt].vis=true;
                }
                else
                {
                    for(int i=1; i<=r; i++)
                    {
                        if((!s[i].vis) && s[i].f && s[i].n>maxn)maxn=s[i].n,maxt=i;
                    }
                    s[maxt].vis=true;
                }
                flag=!flag;
                rx--;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
