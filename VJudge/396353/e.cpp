#include<bits/stdc++.h>
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n,k;
int f[203][203][203];
string s,t;

int dfs(int cur ,int deep,int sum)
{

}

void Solve()
{
    n=qrd();k=qrd();
    cin>>s>>t;
    cout<<dfs(0,k,0)<<endl;
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
