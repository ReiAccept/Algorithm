#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
string str;
map<string,int> m;

void Solve()
{
    cin>>str;
    if(m.find(str)==m.end())
    {
        m[str]=1;
        cout<<"OK"<<endl;
    }
    else
    {
        cout<<str<<m[str]<<endl;
        m[str+to_string(m[str])]=1;
        m[str]++;
    }
}

int main()
{
    int T=qrd();
    while(T--) Solve();
    return 0;
}
//查找数据用Map.find(key);可以通过键来查。(切记不要用int value=Map[key];这样会在Map中增加这个key,而value就是缺省值)会返回迭代器的地址,key不存在的话迭代器的值为Map.end()
