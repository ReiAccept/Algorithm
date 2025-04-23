#include <bits/stdc++.h>
#define pt(x) cout << x << endl;
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read()
{
    char c;
    int num, f = 1;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1;
    num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return f * num;
}
vector<int> ans;
int f[10] = {0, 1, 4, 2};
void work()
{
    int n = read(), len = 0;
    len = n / 4 * 4 + f[n % 4];
    printf("%d\n", len);
    if(n % 4 == 1)
    {
        printf("1");
        n -= 1;
    }
    if(n % 4 == 2)
    {
        printf("0001");
        n -= 2;
    }
    if(n % 4 == 3)
    {
        printf("01");
        n -= 3;
    }
    while(n)
    {
        printf("1001");
        n -= 4;
    }
    printf("\n");
}
signed main()
{
    int Case = read();
    while(Case--) work();
    return 0;
}


/*
n%4==0的时候就是1001 1001 1001 1001
n%4==1的时候就是1 1001 1001 1001
n%4==2就 0001 1001 1001 1001
n%4==3就 01 1001 1001 1001
i^2-(i-1)^2-(i-2)^2+(i-3)^2=4
*/
