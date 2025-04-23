#include<iostream>

using namespace std;

int n,r;
string ans;

void calc(int x,int base)
{
    if(x==0) return;
    ans=to_string(x%base)+ans;
    calc(x/base,base);
}

int main()
{
    cin>>n>>r;
    calc(n,r);
    cout<<ans<<endl;
    return 0;
}
/*
#include<cstdio>

using namespace std;

int d2b(int n,int b,char c[])
{
    int i=0,k;
    while(n!=0)
    {
        k=n%b;
        n/=b;
        if(k<0)
        {
            k-=b;
            n+=1;
        }//这里是负进制的重点
        if(k>9)
            c[i]=char(k-10+'A');
        else 
            c[i]=char(k+'0');
        i++;
    }
    return i-1;
}

int main()
{
    int a,n,i;
    char b[40];
    scanf("%d%d",&a,&n);
    printf("%d=",a);
    if(a==0)
        printf("0");
    for(i=d2b(a,n,b);i>=0;i--)
        printf("%c",b[i]);
    printf("(base%d)",n);
}
*/
