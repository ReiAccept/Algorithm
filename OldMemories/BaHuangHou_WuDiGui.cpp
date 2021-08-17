#include <iostream>
#include <cstdio>

using namespace std;

bool a[8][8];
bool hang(int x,int y);
bool lie(int x,int y);
bool xie(int x,int y);
bool judge(int x,int y);

int main()
{
    freopen("data.out","w",stdout);
    int flag=0,i=0;
    for(;i<=7;i++)
    {
        int fl=0,k=0;
        for(;k<=7;k++)
            {
                a[i][k]=judge(i,k);
                if(a[i][k]==false)
                    fl++;
                else
                    {flag++;break;}
                if(fl==8)
                {
                    fl=0;
                    i--;
                    for(int bg=0;bg<7;bg++)
                        if([i][bg]==0)
                        {
                            k=bg++;
                            continue;
                        }
                }
                    
                
                
                //if(flag==8)
                    //break;
            }
    }

    return 0;
}

bool hang(int x,int y)
{
    for(int i=0;i<=7;i++)
        if(a[i][y]==true)
            return false;
    return true;
}

bool lie(int x,int y)
{
    for(int i=0;i<=7;i++)
        if(a[x][i]==true)
            return false;
    return true;
}

bool xie(int x,int y)
{
    int flag,temp;
    flag=x+y;
    temp=(x*10+y)%11;
    for(int i=0;i<=7;i++)
        for(int k=0;k<=7;k++)
            if(i+k==7 ||(i*10+k)%11==temp)
                if(a[i][k]==true)
                    return false;
    return true;
}

bool judge(int x,int y)
{
    if(hang(x,y)&&lie(x,y)&&xie(x,y))
        return true;
    else
        return false;
}