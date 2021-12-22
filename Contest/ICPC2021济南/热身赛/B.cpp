#include<bits/stdc++.h>

using namespace std;

const int SIZE=10100000;
int head[SIZE],ver[SIZE<<1],Next[SIZE<<1],w[SIZE];
int dfn[SIZE],low[SIZE],n,m,tot,num;
bool bridge[10000010];
int ans;

int g[1003][1003];

void add(int x,int y,int c) {
    ver[++tot]=y,Next[tot]=head[x],head[x]=tot;w[tot]=c;
}

void tarjan(int x,int in_edge) {
    dfn[x] = low[x] =++num;
    for(int i=head[x];i;i=Next[i]) {
        int y=ver[i];
        if(!dfn[y]) {
            tarjan(y,i);
            low[x]=min(low[x],low[y]);

            if(low[y]>dfn[x]) {
                bridge[i]=bridge[i^1]=true;
            }
        } else if(i!=(in_edge^1)){
            low[x]=min(low[x],dfn[y]);
        }
    }
}

void work() {

    for(int i=1;i<=m;i++) {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        add(x,y,c),add(y,x,c);
        // g[x][y]=g[y][x]=c;
    }
    int flag=0;
    for(int i=1;i<=n;i++) {
        if(!dfn[i]) {
            tarjan(i,0);
            flag++;
        }
    }
    int cnt=0;
    for(int i=2;i<tot;i+=2) {
        if(bridge[i]) {
            // ans=min(ans,g[ver[i^1]][ver[i]]);
            // printf("DBG:ANS:%d W_I:%d\n",ans,w[i]);
            ans=min(ans,w[i]);
            cnt++;
        }
    }
    
    if(cnt==0 || ans==0x3f3f3f3f) {
        printf("-1\n");
        return;
    }
    if(flag>1) {
        printf("0\n");
        return;
    } else {
        printf("%d\n",max(ans,1));
    }
}

signed main() {
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
            num=0;
            tot=1;
            ans=0x3f3f3f3f;
            for(int i=0;i<=n*2;i++) dfn[i]=0;
            for(int i=0;i<=n*2;i++) low[i]=0;
            for(int i=0;i<=n*2;i++) head[i]=0;
            for(int i=0;i<=n*2;i++) Next[i]=0;
            for(int i=0;i<=m*2;i++) w[i]=0;
            for(int i=0;i<=m*2;i++) ver[i]=0;
            for(int i=0;i<=2*m;i++) bridge[i]=0;
        work();
    }
    return 0;
}