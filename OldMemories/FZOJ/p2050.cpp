#include<cstdio>
#include<iostream>

using namespace std;

int tree[101];
int n,m,maxn,maxnroot,root=-1;

int main()
{
    cin>>n>>m;
	for(int i=1;i<=m;i++)
    {
       int x,y;
       cin>>x>>y;
	   tree[y]=x;
	}
    for(int i=1;i<=n;i++)
	    if(tree[i]==0)
            root=i;
     for(int i=1;i<=n;i++)
     {
         int sum=0;
         for(int j=1;j<=n;j++)
             if(tree[j]==i)
                 sum++;
         if(sum>maxn)
         {
             maxn=sum;
             maxnroot=i;
         }
     }
	 printf("%d\n%d\n",root,maxnroot);
     for(int i=1;i<=n;i++)
         if(tree[i]==maxnroot)
             printf("%d ",i);
     return 0;
 }
