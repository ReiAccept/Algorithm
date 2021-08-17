#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int a,b,c,d;
    int id,sum;
}a[1003];

int n;

bool cmp(Node a,Node b)
{
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    else 
        return a.id<b.id;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
        a[i].sum=a[i].a+a[i].b+a[i].c+a[i].d;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i].id==1)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
