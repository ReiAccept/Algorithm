#include <iostream>

using namespace std;

struct tree{
    int l,r;
    int h;
};

int n,height,x,whight[100];
tree ch[17];

void dfs(int i,int);

int main()
{
    freopen("data.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ch[i].l>>ch[i].r;
        ch[i].h=i+1;
    }
        dfs(1,0);
        for(int i=0;i<100;i++)
            x=max(x,whight[i]);
        cout<<x<<" "<<height+1<<endl;
        return 0;
}

void dfs(int i ,int deep)
{
    if(deep>height)
        height=deep;
    whight[deep]++;
    if(ch[i].l)
        dfs(ch[i].l,deep+1);
    if(ch[i].r)
        dfs(ch[i].r,deep+1);
}

/*
#include<iostream>
using namespace std;
int ch[17][2];
int width[1000];//用来记录每一层的宽度
int x=0,deep=0,height=0;//deep用来记录当前高度，height用来记录最大高度
void dfs(int i,int deep)
{
    if(deep>height)
        height=deep;
    width[deep]++;
    if(ch[i][0])
        dfs(ch[i][0],deep+1);
    if(ch[i][1])
        dfs(ch[i][1],deep+1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ch[i][0]>>ch[i][1];
    dfs(1,1);
    for(int i=1;i<=1000;i++)
    {
        if(width[i]>x)
            x=width[i];
    }
    cout<<x<<" "<<height;
}
*/