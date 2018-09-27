#include <iostream>

using namespace std;

int a,b,p,ans;
int f[100010];
bool np[100010];

int findx(int x)
{
    if(f[x]!=x)
        f[x]=findx(f[x]);
    return f[x];
}

int main()
{
    cin>>a>>b>>p;
    ans=b-a+1;
    for (int i=a;i<=b;++i)
        f[i]=i;
    for (int i=2;i<=b;++i)
        if (!np[i])
        {
            if (i>=p)
                for (int j=i*2;j<=b;j+=i)
                {
                    np[j]=true;
                    if (j-i>=a && findx(j)!=findx(j-i))
                    {
                        f[findx(j)]=findx(j-i);
                        --ans;
                    }
                }
            else
                for (int j=i*2;j<=b;j+=i)
                    np[j]=true;
        }
    cout<<ans<<endl;
    return 0;
}
