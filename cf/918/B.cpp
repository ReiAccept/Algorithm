#include<bits/stdc++.h>

using namespace std;

int n,m;
string name[10001],id[10001],namex,idx;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) cin>>name[i]>>id[i];
    for(int i=1;i<=m;i++)
    {
        cin>>namex>>idx;
        idx.erase(idx.size()-1,1);
        for(int j=1;j<=n;j++)
            if(id[j]==idx)
                cout<<namex<<" "<<idx<<"; #"<<name[j]<<endl;
    }
    return 0;
}
