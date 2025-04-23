#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int start,end;
}work[10003];

int n,k,num=1;
int starttime[10003],f[10003];

bool cmp(Node a,Node b)
{
    return a.start>b.start;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>work[i].start>>work[i].end;
        starttime[work[i].start]++;
    }
    sort(work+1,work+k+1,cmp);
    for(int i=n;i>=1;i--)
    {
        if(!starttime[i])
            f[i]=f[i+1]+1;
        else
            for(int j=1;j<=starttime[i];j++)
            {
                f[i]=max(f[i],f[i+work[num].end]);
                num++;
            }
    }
    cout<<f[1]<<endl;
    return 0;
}
