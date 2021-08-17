#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
int a[100003];

bool chk()
{
    for(int i=1;i<n;i++) if(a[i]>a[i+1]) return false;
    return true;
}

void prt()
{
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
}
void Solve()
{
    n=qrd();
    for(int i=1;i<=n;i++) a[i]=qrd();
    if(chk())
    {
        printf("yes\n1 1\n");
        return;
    }
    int cur=1;
    while(a[cur]<a[cur+1])cur++;
    int curd=cur+1;
    while(a[curd]>a[curd+1])curd++;
    if(curd>n)curd--;
    reverse(a+cur,a+curd+1);
    //prt();
    //printf("%d %d\n",cur,curd);
    if(chk())printf("yes\n%d %d\n",cur,curd);
    else printf("no\n");
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
