//这踏马不是NOIP2010关押罪犯吗
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    int x,y,v;
}a[100003];

int n,m;
int father[100003],flag[100003];

bool cmp(node a,node b)
{
    return a.v>b.v;
}

int find(int x)
{
    if (father[x]!=x) 
		father[x]=find(father[x]);
    return father[x];
}

void mix(int x,int y)
{
    father[find(y)]=find(x);
}

int main()
{
    freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>n>>m;
    for (int i=1;i<=n;i++) 
		father[i]=i;
    for (int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].v;
	sort(a+1,a+m+1,cmp);
    for (int i=1;i<=m;i++)
    {
        if (find(a[i].x)==find(a[i].y)) 
		{
			cout<<a[i].v<<endl;
			return 0;
		}
        if (flag[a[i].x]==0)
            flag[a[i].x]=a[i].y;
        if (flag[a[i].y]==0)
            flag[a[i].y]=a[i].x;
        mix(a[i].x,flag[a[i].y]);
        mix(a[i].y,flag[a[i].x]);
    }
    cout<<"0"<<endl;
	return 0;
}
