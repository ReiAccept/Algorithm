#include<cstdio>
#include<iostream>

using namespace std;

int t;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        while(a && b && !(a==1 && b==1))
        {
            //cout<<a<<" "<<b<<endl;
            if(a>b) swap(a,b);
            int tmp1=a;
            if(b<(a*2)) tmp1=b/2;
            a-=tmp1;b-=(tmp1<<1);
            //cout<<a<<" "<<b<<endl;
        }
        if(!a && !b) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
