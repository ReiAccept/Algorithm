#include<cstdio>
#include<iostream>
#include<climits>

using namespace std;

struct stone
{
    int wi,vi;
} st[200005];

struct qujian
{
    int li,ri;
} qj[200005];

int n,m,Wmax,flag_num,res,ans;
long long s,flag_s,flag,res_n=INT_MAX;

long long Abs(long long x)
{
    if(x<0)
        return -x;
    else
        return x;
}

int main()
{
    freopen("qc.in","r",stdin);
    freopen("qc.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&st[i].wi,&st[i].vi);
        Wmax=max(Wmax,st[i].wi);
    }
    for(int i=1; i<=m; i++)
        scanf("%d%d",&qj[i].li,&qj[i].ri);
    for(int Wnow=1; Wnow<=Wmax; Wnow++)
    {
        flag=0;
        for(int i=1; i<=m; i++)
        {
            flag_s=0;
            flag_num=0;
            for(int li=qj[i].li; li<=qj[i].ri; li++)
            {
                if(st[li].wi>=Wnow)
                {
                    flag_s+=st[li].vi;
                    flag_num++;
                }
            }
            flag+=Abs(flag_num*flag_s-Wnow);
        }
        if(flag<=res_n)
        {
            res_n=flag;
            res=Wnow;
        }
    }
    cout<<res_n<<endl;
    return 0;
}
