#include<cstdio>
#include<iostream>

using namespace std;

char m[27];
bool used[27];
string a,b,c;

void printx()
{
    for(int i=0;i<26;i++)
        printf("%c ",m[i]);
    printf("\n");
}

int main()
{
    cin>>a>>b>>c;
    for(int i=0;i<a.size();i++)
    {
        int c1=a[i]-'A';
        if(m[c1]==0 && !used[b[i]-'A'])
        {
            m[c1]=b[i];
            used[b[i]-'A']=true;
        }
        else if(m[c1]==b[i]) continue;
        else if(m[c1]!=b[i])
        {
            printf("Failed\n");return 0;
        }
        //printx();
    }
    for(int i=0;i<26;i++)
        if(!m[i])
        {
            printf("Failed\n");return 0;
        }
    for(int i=0;i<c.size();i++) printf("%c",m[c[i]-'A']);
    return 0;
}
