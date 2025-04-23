#include<bits/stdc++.h>
#define ll long long
#define uint unsigned int
#define ull unsigned long long
using namespace std;
int qrd(){int a=0,b=1,c=getchar();while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();return a*b;}

int a,b;
int ans[4003];
stack<int> Stack;

bool query(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    char s[3]; scanf("%s", s);
    return s[0] == 'Y';
}

void Solve()
{
    a=qrd();b=qrd();
    if (a<=b) 
    {
        puts("Impossible");
        return;
    }
    for(int i=0;i<a+b;i++)
    {
        if (Stack.empty()) Stack.push(i);
        else
        {
            if (query(Stack.top(), i)) Stack.push(i);
                else Stack.pop();
        }
    }

    for(int i = 0; i < a + b; ++i) if (query(Stack.top(), i)) ans[i] = 1;
    printf("! ");
    for(int i = 0; i < a + b; ++i) printf("%d", ans[i]);
}

int main()
{
    int T=1;//qrd();
    while(T--) Solve();
    return 0;
}
