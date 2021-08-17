#include<bits/stdc++.h>

using namespace std;

int s,w,n,sum;
int wi[303];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    scanf("%d",&s);
    while(s--)
    {
        scanf("%d%d",&w,&n);
        sum=0;
        for(int i=0; i<n; i++)scanf("%d",wi+i);
        sort(wi,wi+n,cmp);
        int l=0,r=n-1;
        while(l<=r)
        {
            if(wi[l]+wi[r]<=w)
            {
                l++;
                r--;
            }
            else
            {
                l++;
            }
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
