#include<bits/stdc++.h>

using namespace std;

int n,m;
bool flag;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;
    for(int i=n; i>=m+1; i--)
    {
        flag=false;
        for(int j=2;j<=m; j++)
        {
            if(!(i%j))
            {
                flag=true;
                break;
            }
            else
            {
                flag=false;
            }
        }
        if(!flag)
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
