#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,k;
string str;
int p[1003];

void work()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        int num=0;
        for(int j=33;j<(int)str.size();j++) num=num*10+(str[j]-'0');
        p[i]=num;
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=k;i++)printf("%d ",p[i]);
    printf("\n");
    return;
}

signed main()
{
    int Case = read();
	while(Case--) work();
    return 0;
}
