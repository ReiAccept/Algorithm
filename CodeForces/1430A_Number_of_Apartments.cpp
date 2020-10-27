#include<bits/stdc++.h>
#define cnt (i*3+j*5+k*7)

using namespace std;

int n;
struct sol
{
    int a,b,c;
    bool sol=false;//o 表示是否有解
} ans[10003];

void INIT()
{
    for(int i=0; i<=1000/3; i++) //枚举3窗的屋子的个数
        for(int j=0; j<=1000/5; j++) //枚举5窗的屋子的个数
            for(int k=0; k<=1000/7; k++) //枚举7窗的屋子的个数
                if(!ans[cnt].sol) ans[cnt].a=i,ans[cnt].b=j,ans[cnt].c=k,ans[cnt].sol=true;
}

void Solve()
{
    ;
    cin>>n;
    ans[n].sol?printf("%d %d %d\n",ans[n].a,ans[n].b,ans[n].c):puts("-1");//输出
}

int main()
{
    INIT();
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--) Solve();
    return 0;
}
