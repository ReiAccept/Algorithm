#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e5+3;

int mx,my,n;//,ex,ey;
char s[MAXN];
map<char,int> cnt,dx,dy;

bool chk(char *a)
{
    int x=0,y=0;
    for(int i=0;i<4;i++) {
        for(int j=1;j<=cnt[a[i]];j++) {
            x+=dx[a[i]];
            y+=dy[a[i]];
            //printf("DEBUG: X: %d Y: %d\n",x,y);
            if(x==mx && y==my) return false;
        }
    }
    return true;
}

void work()
{
    scanf("%d%d",&mx,&my);
    scanf("%s",&s); n=strlen(s);
    for(int i=0;i<n;i++) {
        cnt[s[i]]++;
    }
    //ex=cnt['U']+cnt['D']; ey=cnt['L']+cnt['R']; //其实我不太明白,为什么判断重点是否有炸弹这里炸了
    if((mx==0 && my==0) /*|| (mx==ex && my==ey)*/) {
        printf("Impossible\n");
        return;
    }
    char a[]="LRUD";
    bool flag=false;
    do {
        if(chk(a)) {
            flag=true;
            break;
        }
    } while(next_permutation(a,a+4));
    if(flag) {
        for(int i=0;i<4;i++) {
            for(int j=1;j<=cnt[a[i]];j++) {
                printf("%c",a[i]);
            }
        }
        printf("\n");
    } else {
        printf("Impossible\n");
    }
    return;
}

signed main()
{
    dx['L']=-1; dx['R']=1;
    dy['D']=-1; dy['U']=1;
    int Case; scanf("%d",&Case);
    for(int T=1; T<=Case; T++) {
        work();
        cnt.clear();
    }
    return 0;
}
