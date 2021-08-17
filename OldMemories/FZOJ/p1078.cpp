#include <cstdio>

using namespace std;

int b[20]= {0,1,1};

int main()
{
    int a,n,m,x,i,k=0;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    if(x==1)
    {
        printf("%d",a);
        return 0;
    }
    for(i=3; i<20; i++)
        b[i]=b[i-1]+b[i-2];
    if(n>4)
        k=(m-(b[n-3]+1)*a)/(b[n-2]-1);
    printf("%d",(b[x-1]-1)*k+(b[x-2]+1)*a);
    return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
    int a,n,m,x,b;
    int i;
    int aa[1000]= {0},bb[1000]= {0};
    int ia[1000]= {0},ib[1000]= {0};
    cin >> a >> n >> m >> x;
    aa[1]=1;
    bb[1]=0;
    ia[1]=1;
    ib[1]=0;
    aa[2]=1;
    bb[2]=0;
    ia[2]=0;
    ib[2]=1;
    for(i=3; i<=n-1; i++)
    {
        aa[i]+=aa[i-1]+ia[i-2];
        bb[i]+=bb[i-1]+ib[i-2];
        ia[i]=ia[i-1]+ia[i-2];
        ib[i]=ib[i-1]+ib[i-2];
    }
    aa[n]=aa[n-1];
    bb[n]=bb[n-1];
    b=(m-aa[n]*a)/bb[n];
    cout << aa[x]*a+bb[x]*b;
    return 0;
}
*/
