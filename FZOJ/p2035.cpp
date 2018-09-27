#include<cstdio>

using namespace std;

int n,head,tail;
int deg[103],q[103];
bool grap[103][103];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int son;
        scanf("%d",&son);
        while(son!=0)
        {
            grap[i][son]=true;
            deg[i]++;
            scanf("%d",&son);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0)
            q[tail++]=i;
    }
    while(head!=tail)
    {
        int cur=q[head++];
        for(int i=1;i<=n;i++)
        {
            if(grap[i][cur])
            {
                grap[i][cur]=false;
                deg[i]--;
                if(deg[i]==0)
                    q[tail++]=i;
            }
        }
    }
    //for(int i=n-1;i>=0;i--) printf("%d ",q[i]);
    //printf("\n%d %d %d\n",n,head,tail);
    printf("%s\n",n==tail?"YES":"NO");
    return 0;
}
