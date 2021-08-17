#include<iostream>

using namespace std;

int n,sum;
int fa[27];
char ans1[203],ans2[203],s1[100003],s2[100003];

int find(int x)
{
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

inline void unionxy(int x,int y,int i)
{
    if(find(x)!=find(y)) ans1[++sum]=s1[i],ans2[sum]=s2[i],fa[find(x)]=find(y);
}

int main()
{
    cin>>n;
    for(int i=1;i<=26;i++) fa[i]=i;
    for(int i=1;i<=n;i++) cin>>s1[i];
    for(int i=1;i<=n;i++) cin>>s2[i];
    for(int i=1;i<=n;i++) unionxy(s1[i]-'a',s2[i]-'a',i);
    cout<<sum<<endl;
    for(int i=1;i<=sum;i++) cout<<ans1[i]<<" "<<ans2[i]<<endl;
    return 0;   
}
