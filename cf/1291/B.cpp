#include<cstdio>
#include<iostream>

using namespace std;

int T,n,last,cur,lastraw;
bool flag,up=true;

int read();

int main()
{
    //freopen("ans.txt","w",stdout);
    T=read();
    while(T--)
    {
        n=read();
        last=read();
        if(n==1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(n==2)
        {
            int lastx=read();
            if(lastx==0 && last==0)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
            continue;
        }
        lastraw=last;last=0;int i;
        flag=false,up=true;
        for(i=2;i<=n;i++)//up
        {
            cur=read();
            if(cur>=last+1)
            {
                last++;
                lastraw=cur;
            }
            else
            {
                if(lastraw==cur)last=cur-1;
                else last=cur;
                break;
            }
            //printf("%d %d %d\n",i,last,cur);
        }
        for(i=i+1;i<=n && last>=0;i++)//down
        {
            cur=read();
            if(cur>=last-1)last--;
            else last=cur;
            //printf("%d %d %d\n",i,last,cur);
        }
        if(last<0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}





int read()
{
    int re=0,ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9')
    {
        re=re*10+ch-'0';
        ch=getchar();
    }
    return re;
}
