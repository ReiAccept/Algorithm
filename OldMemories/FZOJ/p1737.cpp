#include <cstdio>

using namespace std;

int zuo,you;
char word;

int main()
{
    while(true)
    {
        word=getchar();
        //scanf("%c",&word);
        if(word=='(')
            zuo++;
        if(word==')')
            you++;
        if(word=='@')
            break;
    }
    if(zuo==you)
        printf("YES");
    else
        printf("NO");
    return 0;
}
