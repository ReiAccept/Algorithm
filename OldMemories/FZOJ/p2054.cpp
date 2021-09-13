#include <cstdio>

using namespace std;

int d,l,cur;
bool tree[524288*2+23];

int main()
{
    scanf("%d%d",&d,&l);
    for(int i=1; i<=l; i++)
    {
        cur=1;
        for(int j=1; j<d; j++)
        {
            tree[cur]=(!tree[cur]);
            if(!tree[cur])
                cur=cur*2+1;
            else
                cur*=2;
        }
    }
    printf("%d\n",cur);
    return 0;
}
