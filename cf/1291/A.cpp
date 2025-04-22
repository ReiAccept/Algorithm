#include<cstdio>
#include<iostream>

using namespace std;

int T,n,num;
bool flag;
char ans;
string str;
//char a[]={'1','3','5','7','9'};

inline bool checkc(char c)
{
    return (c=='1' || c=='3' || c=='5' || c=='7' || c=='9');
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cin>>str;
        num=0;flag=false;
        for(int i=0;i<n;i++)
        {
            if(checkc(str[i]))
            {
                num++;
                if(num==1)ans=str[i];
                else if(num==2)
                {
                    cout<<ans<<str[i]<<endl;
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)cout<<"-1"<<endl;
    }
    return 0;
}
