#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int n;
vector<int>a;
string s;

void Solve()
{
    n=qrd();
    for (int i=1;i<=n;i++) 
    {
        cin>>s;
        if(s[0]!='-' && (int)s.size()<9) 
        {
            int x=0;
            for (int j=0;j<(int)s.size();j++) x=x*10+s[j]-'0';
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end());
    int i=0,j=0;
    while(true)
    {
        if (j>=(int)a.size() || i!=a[j]) 
        {
            cout<<i<<endl;
            return;
        }
        i++;j++;
    }
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
