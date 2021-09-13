#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int l, r;
} arr[102];

bool cmp(Node a, Node b)
{
    return a.r < b.r;
}

int n,ans,flag;

int main()
{
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++) scanf("%d%d", &arr[i].l, &arr[i].r);
        sort(arr,arr+n,cmp);
        flag=arr[0].r;
        ans=1;
        for(int i=1;i<n; i++)
            if(arr[i].l >= flag)
            {
                ans++;
                flag = arr[i].r;
            }
        printf("%d\n",ans);
    }
    return 0;
}
