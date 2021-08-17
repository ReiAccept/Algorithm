//不知为何没AC
#include<cstdio>
#include<cstring>

using namespace std;

struct noname
{
	int father;
	int val;
}node[103];

int w,n,m,flag;

int findx(int x)
{
	if(node[x].father!=x)
	{
		int t=findx(node[x].father);
		node[x].val+=node[node[x].father].val;
		node[x].father=t;
	}
	return node[x].father;
}

void unionx(int x,int y,int val)
{
	int p=findx(x);
	int q=findx(y);
	if(p!=q)
	{
		node[p].father=q;
		node[p].val=node[y].val-node[x].val-val;
	}
	else if(node[y].val-node[x].val!=w)
		flag=true;
}

int main()
{
	scanf("%d",&w);
	while(w--)
	{
		memset(node,0,sizeof(node));
        flag=false;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			node[i].father=i;
		for(int i=1;i<=m;i++)
		{
			int s,t,v;
			scanf("%d%d%d",&s,&t,&v);
			unionx(s-1,t,v);
		}
		if(flag)
			printf("false\n");
        else 
			printf("true\n");
	}
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int father[101],v[101],flag,t;
int find(int x)
{
    if(father[x]==x)return x;
    t=find(father[x]);
    v[x]+=v[father[x]];
    father[x]=t;
    return father[x];
}
void work(int x,int y,int w)
{
    int p=find(x),q=find(y);
    if(p!=q)
    {
              father[p]=q;
              v[p]=v[y]-v[x]-w;
              }
    else if(v[y]-v[x]!=w)flag=1;
}
int main()
{
    int w,n,m;
    scanf("%d",&w);
    while(w--)
    {
              memset(v,0,sizeof(v));
              flag=0;
              scanf("%d%d",&n,&m);
              for(int i=0;i<=n;i++)father[i]=i;         
              for(int i=1;i<=m;i++)
              {
                      int x,y,z;
                      scanf("%d%d%d",&x,&y,&z);
                      work(x-1,y,z);
                      }
              if(flag)printf("false\n");
              else printf("true\n");
              }
    return 0;
}
*/
