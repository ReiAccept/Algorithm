#include <bits/stdc++.h>
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define ull unsigned long long

using namespace std;


string n;

void work()
{
    cin>>n;
    for(int i=0; i<(int)n.size(); i++)
    {
        int tmp=n[i]-'0';
        //cout<<tmp<<endl;
        if(tmp%8==0)
        {
            cout<<"YES"<<endl<<tmp<<endl;
            return;
        }
        for(int j=i+1; j<(int)n.size(); j++)
        {
            int tmp2=tmp*10+n[j]-'0';
            //cout<<tmp<<endl;
            if(tmp2%8==0)
            {
                cout<<"YES"<<endl<<tmp2<<endl;
                return;
            }
            for(int k=j+1; k<(int)n.size(); k++)
            {
                int tmp3=tmp2*10+n[k]-'0';
                //cout<<tmp<<endl;
                if(tmp3%8==0)
                {
                    cout<<"YES"<<endl<<tmp3<<endl;
                    return;
                }

            }
        }
    }
    cout<<"NO"<<endl;
    return;
}

signed main()
{
    int Case = 1;//read();
    while(Case--) work();
    return 0;
}
//小学奥数->当一个数想被8整除,末尾3个数一定是8的倍数
