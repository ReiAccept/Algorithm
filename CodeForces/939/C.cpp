#include<cstdio>

using namespace std;

int n,s,f,ans,maxx,now;
int a[100003],b[100003];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=b[i-1]+a[i];
    scanf("%d%d",&s,&f);
    for(int i=1;i<=n;i++)
    {
        if(i<=s) now=b[f-i]-b[s-i];
        else if(i<=f) now=b[f-i]+b[n]-b[s-i+n];
        else  now=b[f-i+n]-b[s-i+n];
        (now>maxx)?(ans=i,maxx=now):ans=ans;
    }
    printf("%d",ans);
    return 0;
}
//MDZZ,地理时区比题目难????
