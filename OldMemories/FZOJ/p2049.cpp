#include<stack>
#include<cstdio>

using namespace std;

stack<int> q;
int n,ans,tmp;

int main()
{
    scanf("%d",&n);
    scanf("%d",&tmp);
    ans=n;
    q.push(tmp);
    for(int i=2; i<=n; i++)
    {
        scanf("%d",&tmp);
        while(!q.empty()&&tmp<=q.top())
        {
            if(tmp==q.top())
                ans--;
            q.pop();
        }
        q.push(tmp);
    }
    printf("%d\n",ans);
    return 0;
}
