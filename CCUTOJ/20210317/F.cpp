#include<bits/stdc++.h>

using namespace std;

int n,s;
int r[10];
map<int,bool> m;

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        m.clear();
        for(int k=1;k<=n;k++)
        {
            cin>>s;
            for(int i=0;i<=9;i++)r[i]=0;
            for(int tmp,i=1;i<=s;i++)
            {
                cin>>tmp;
                r[tmp]++;
            }
            int sx=0;
            for(int j=9;j>=0;j--) if(r[j])sx=sx*10+j;
            m[sx]=true;
        }
        cout<<m.size()<<endl;
    }
    return 0;
}
