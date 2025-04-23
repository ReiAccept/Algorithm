#include<cstdio>

using namespace std;

int cnt;

int main()
{
    while(true)
    {
        char c=(char)getchar();
        if(c=='(') cnt++;
        if(c==')') cnt--;
        if(cnt<0)
        {
            printf("NO\n");
            break;
        }
        if(c=='@' && cnt==0){
            printf("YES\n");
            break;
        }
        if(c=='@' && cnt!=0)
        {
            printf("NO\n");
            break;
        }
    }
    return 0;
}
