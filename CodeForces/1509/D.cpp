#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
int n;
int a[3][501009];

string buildx(int x,int y,int cxx)
{
    string tmp1=""; int ptr=1;
    for(int i = 1; i <= 2 * n; i++)
        if(a[y][i] == cxx)
        {
            while(ptr <= 2 * n && a[x][ptr] != a[y][i]) tmp1 += a[x][ptr++] ? "1" : "0";
            tmp1 += a[y][i] ? "1" : "0";
            ptr++;
        }
        else tmp1 += a[y][i] ? "1" : "0";
    while(ptr <= 2 * n) tmp1 += a[x][ptr++] ? "1" : "0";
    return tmp1; 
}
string build(int x, int y)
{
    string tmp1 =buildx(x,y,0),tmp2 =buildx(x,y,1);
    if(tmp1.size() < tmp2.size()) return tmp1;
    else return tmp2;
}
void work()
{
    n = read();
    for(int j = 0; j < 3; j++)
        for(int i = 1; i <= 2 * n; i++)
            scanf("%1d", &a[j][i]);
    string t1 = build(0, 1),t2 = build(0, 2),t3 = build(1, 2);
    if(t3.size() < t2.size()) swap(t3, t2);
    if(t2.size() < t1.size()) swap(t2, t1);
    cout << t1 << endl;
}
signed main()
{
    int Case = read();
    while(Case--) work();
    return 0;
}
