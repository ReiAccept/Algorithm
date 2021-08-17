#include<cstdio>
#include<iostream>

using namespace std;

int s,p,n,m;
char c;

int main()
{
    while(scanf("%d%d%d",&s,&p,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>c>>m;
            if(c=='x' && m+s<=p)
                s+=m;
            if(c=='y' && s-m>=0)
                s-=m;
        }
        cout<<s<<endl;
    }
    return 0;
}
