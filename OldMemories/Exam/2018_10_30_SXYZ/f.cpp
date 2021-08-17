#include<map>
#include<iostream>

using namespace std;

int n,ans;
int a[100003],feb[50]={0,1,1};
map<int,int> m;

bool check(int x);
bool query(int x);
void add(int x);

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=47;i++) feb[i]=feb[i-1]+feb[i-2];
    for(int i=1;i<=n;i++)
    {
        if(check(a[i]))
            add(a[i]);
        else
        {
            m.clear();
            add(a[i]);
            ans++;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}

bool check(int x)
{
    for(int i=1;i<=46;i++)
    {
        int ex=feb[i]-x;
        if(ex>=0 && query(ex))
            return false;
    }
    return true;
}

bool query(int x)
{

}

void add(int x)
{

}
