#include <bits/stdc++.h>

using namespace std;

int pre[200009], nxt[200009];
char c[200009];

void del(int x,int x2)
{
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
    nxt[pre[x2]] = nxt[x2];
    pre[nxt[x2]] = pre[x2];

}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s", c + 1);
        int n = (int)strlen(c + 1);
        int tmp = n,now=1;
        for(int i = 1; i <= n; i++)pre[i] = i - 1, nxt[i] = i + 1;
        while(now != n + 1)
        {
            if(!pre[now] || c[now] == 'A')
            {
                now = nxt[now];
                continue;
            }
            del(pre[now],now);
            tmp -= 2;
            now = nxt[now];
        }
        cout<<tmp<<endl;
    }
    return 0;
}

