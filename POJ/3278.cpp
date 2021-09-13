//By Luogu P1588
#include<iostream>
#include<queue>
#include<cstdio>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,k;
int step[100003];
bool v[100003];
queue<int>q;

void bfs()
{
    q.push(n);
    v[n]=true;
    while(!q.empty())
    {
        int nxt,now=q.front();
        q.pop();
        //printf("%d ",now);
        for(int op=1;op<=3;op++)
        {
            if(op==1)nxt=now*2;
            else if(op==2)nxt=now+1;
            else nxt=now-1;
            if(!(nxt>=0 && nxt<=100000))continue;
            if(!v[nxt])
            {
                q.push(nxt);
                v[nxt]=true;
                step[nxt]=step[now]+1;
            }
            if(nxt==k)
            {
                cout<<step[nxt]<<endl;
                return;
            }
        }
    }
}

void work()
{
    n=read();k=read();
    if(n>=k)cout<<n-k<<endl;
    else bfs();
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
