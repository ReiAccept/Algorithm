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
        if(a*2<b || b*2<a) 
        {
            printf("NO\n");
            continue;
        }
        //if(a>b) swap(a,b);
        int y=(2*b-a)/3;
        int x=(a-y)/2;
        //cout<<x<<" "<<y<<endl;
        if((a==(2*x)+y) && (b==(2*y)+x) && (x>=0) && (y>=0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
