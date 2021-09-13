#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n;
int ansx[200003];

void work()
{
    //n=read();
    for(int n=1;n<=1000;n++)
    {
        int ans=0;
        printf("N:%lld\n",n);
        for(int i=n;i<=n;i++)
        {
            int iw=i%10;
            int it=i;
            while(it>10)it/=10;
            //printf("I:%d ANS:",i);
            for(int j=1;j<=n;j++)
            {
                int jw=j%10;
                int jt=j;
                while(jt>10)jt/=10;
                if(jt==iw && jw==it)
                {
                    ans++;
                    //printf("I:%d J:%d\n",i,j);
                }
            }
        }
        ans=ansx[n-1];
        ansx[n]=ans;
        cout<<ans<<endl;
    }
    return;
}

void work2()
{
    //n=read();
    for(int n=1;n<=1000;n++)
    {
        int ans=0;
        printf("N:%lld ANS:",n);
        for(int i=1;i<=n;i++)
        {
            int iw=i%10;
            int it=i;
            while(it>10)it/=10;
            //printf("I:%d\n",i);
            for(int j=1;j<=n;j++)
            {
                int jw=j%10;
                int jt=j;
                while(jt>10)jt/=10;
                if(jt==iw && jw==it)
                {
                    ans++;
                    //printf("I:%d J:%d\n",i,j);
                }
            }
        }
        //ans+=ansx[n-1];
        //ansx[n]=ans;
        cout<<ans<<endl;
    }
    return;
}

signed main()
{
    freopen("C.out","w",stdout);
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work2();
    }
    return 0;
}
