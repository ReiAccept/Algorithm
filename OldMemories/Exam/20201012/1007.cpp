#include <bits/stdc++.h>
#define int unsigned long long
#define Mid ((l + r) >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
#define ull unsigned long long

using namespace std;

int read()
{
    char c;
    int num, f = 1;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1;
    num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return num * f;
}
int n, a, b, mod, x, y, t, fib[5000009];
int Cir[1009][1009];

int Pow(int a, int p, int mod)
{
    a %= mod;
    int ans = 1;
    for(; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans % mod;
}
void work()
{
    a=read();b=read();mod=read();
    memset(Cir, 0, sizeof(Cir));
    fib[0] = 0,fib[1] = fib[2] = 1,fib[3] = 2 % mod,Cir[0][1] = 1,Cir[1][1] = 2;
    int cnt = 3;
    while(!Cir[fib[cnt - 1]][fib[cnt]])
    {
        Cir[x][y] = cnt++;
        fib[cnt] = (fib[cnt - 1] + fib[cnt - 2]) % mod;
    }
    int x = fib[cnt - 1],  y = fib[cnt];
    int l = Cir[x][y];
    n = Pow(a, b, cnt - l) ;
    cout << fib[n] << endl;
}
signed main()
{
    int Case = read();
    while(Case--) work();
    return 0;
}
/*
斐波那契循环节
一直往后找，直到当前数是之前的循环，
可以求出循环长度
 */
