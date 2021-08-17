#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double money,dazhe;
    int result,k;
    cin>>money>>dazhe;
    result=money/10.0*dazhe;
    k=result%10;
    if(k<5)
        result=result-k;
    else
        result=result-k+10;
        printf("%d\n",result);
    return 0;
}