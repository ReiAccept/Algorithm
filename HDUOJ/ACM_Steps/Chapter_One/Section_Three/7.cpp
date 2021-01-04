#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int a[5];

void work()
{
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    while(true)
    {
        sort(a+1,a+4);
        int last1=a[1];
        bool fst=true;
        do
        {
            if(a[1]==0) continue;
            if(last1!=a[1] || fst)
            {
                if(!fst)cout<<endl;
                last1=a[1];
                fst=false;
                cout<<a[1]<<a[2]<<a[3]<<a[4];
            }
            else cout<<" "<<a[1]<<a[2]<<a[3]<<a[4];
        } while (next_permutation(a+1,a+5));
        cout<<endl;
        cin>>a[1]>>a[2]>>a[3]>>a[4];
        if(!a[1] && !a[2] && !a[3] && !a[4]) break;
        else cout<<endl;
    }
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=1;//read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
