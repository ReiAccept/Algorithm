#include<iostream>

using namespace std;

int T,r,g,b,w;

bool check(int r,int g,int b,int w)
{
    int k=0;
    if(r%2)k++;
    if(g%2)k++;
    if(b%2)k++;
    if(w%2)k++;
    if(k>1)return false;
    return true;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>r>>g>>b>>w;
        int m=min(r,min(g,b));
        int rx=r-m,gx=g-m,bx=b-m,wx=w+(m*3);
        if(check(rx,gx,bx,wx))
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            if(r>0 && g>0 && b>0 && wx>=3)
            {
                wx-=3;
                rx++;
                gx++;
                bx++;
            }
        }
        if(check(rx,gx,bx,wx))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
