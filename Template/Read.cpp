#include<cstdio>
#include<iostream>

using namespace std;

int read(){int re=0,ch=getchar();while (ch<'0' || ch>'9') ch=getchar();while (ch>='0' && ch<='9'){re=re*10+ch-'0';ch=getchar();}return re;}

int main()
{
    int a=read();
    cout<<a<<endl;
    return 0;
}
