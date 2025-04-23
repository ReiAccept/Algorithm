#include<list>
#include<cstdio>

using namespace std;

int n,m;
list<int> l(1,1);//(数据个数,数据)
list<int>::iterator cur[100003];
bool rmd[100003];

int main()
{
    scanf("%d",&n);
    cur[1]=l.begin();
    for(int i=2;i<=n;i++)
    {
        int k,p;
        scanf("%d%d",&k,&p);
        if(!p) cur[i]=l.insert(cur[k],i);
        else cur[i]=l.insert(cur[k].,i);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int num;
        scanf("%d",&num);
        if(!rmd[num]) rmd[num]=true;
    }
    for(list<int>::iterator it=l.begin();it!=l.end();it++) if(!rmd[*it]) printf("%d ",*it);
    return 0;
}
