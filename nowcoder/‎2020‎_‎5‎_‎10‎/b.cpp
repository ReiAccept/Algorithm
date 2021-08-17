#include<cstdio>
#include<iostream>

using namespace std;

long long n;
double res;
char str[5005];
int nx[5005];

int main()
{
    cin>>str;
    for(int i=1; i<=5000; i++)
        if(str[i]=='+')
            nx[++n]=i;
    for(int i=0; i<=n; i++)
    {
        int n=0,x=0;
        sscanf(str+nx[i],"%dd%d",&n,&x);
        //printf("%d %d %d\n",nx[i],n,x);
        if(x==0)
        {
            res+=n;
            continue;
        }
        double ne=(1.0+x)*x/2.0;
        res+=((ne/(double)x)*n);

    }
    if(res>(int)res)cout<<(int)res<<".5"<<endl;
    else cout<<(int)res<<endl;
    return 0;
}
