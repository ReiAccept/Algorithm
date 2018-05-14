#include<cstdio>
#include<cstring>

const int N=1000010;
char s[N];
int Case,n,i,j,mx,now,S;
bool is[26];
int g[26][26],w[26][26],q[26],m;

int main()
{
    scanf("%d",&Case);
    while(Case--)
    {
        for(i=0; i<26; i++)
            is[i]=q[i]=0;
        for(i=0; i<26; i++)
            for(j=0; j<26; j++)
                g[i][j]=w[i][j]=0;
        mx=m=0;
        scanf("%s",s);
        n=strlen(s);
        for(i=1; i<n; i++)
            g[s[i-1]-'a'][s[i]-'a']++;
        is['a'-'a']=1;
        is['e'-'a']=1;
        is['i'-'a']=1;
        is['o'-'a']=1;
        is['u'-'a']=1;
        is['w'-'a']=1;
        is['y'-'a']=1;
        for(i=0; i<26; i++)
            if(!is[i])q[m++]=i;
        for(i=0; i<26; i++)
            for(j=0; j<26; j++)
                if(is[i]||is[j])
                    g[i][j]=0;
        for(i=0; i<m; i++)
            for(j=0; j<m; j++)
                w[i][j]=g[q[i]][q[j]];
        for(S=0; S<1<<m; S++)
        {
            now=0;
            for(i=0; i<m; i++)
                for(j=0; j<m; j++)
                    if(((S>>i)^(S>>j))&1)
                        now+=w[i][j];
            if(now>mx)
                mx=now;
        }
        printf("%d\n",mx);
    }
}
/*
3
consonants
destruction
strength
*/
