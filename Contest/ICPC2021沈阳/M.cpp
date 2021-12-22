#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e6+3;

int n;
char s[MAXN];
map<char,int> m; //m 存储里面每一个字符最后的出现位置
int cntt,xi,xj;
signed main() {
    scanf("%s",s+1);
    n=strlen(s+1);
    int l=1,r=1;
    for(int i=1;i<=n;i++) {
        // printf("DEBUG:I: %d\n",i);
        m[s[i]]=i;
        if(i==1) {
            printf("1 1\n");
            continue;
        }
        if(cntt){
            xj=i;
            xi++;
            if(s[xj]>s[l]) {
                cntt=0; xi=0; l=i; r=i;
                printf("%d %d\n",l,r);
                continue;
            }
            else if(s[xj]==s[l]) {
                if(s[xj]>s[xi]) {
                    l=cntt; cntt=xj; xi=l; r=i;
                }
                else {
                    cntt=xj; xi=l; r=i;
                }
                printf("%d %d\n",l,r);
                continue;
            }

            if(s[xi]==s[xj]){
                r=i;
            }
            else if(s[xi]>s[xj]) {
                cntt=0; xi=0; xj=0; r=i;
            }
            else if(s[xi]<s[xj]) {
                l=cntt;
                // l=max(m[s[i]],cntt); 
                cntt=0; xi=0; xj=0;
                r=i;
            }
            printf("%d %d\n",l,r);
            continue;
        }

        if(s[i]>s[l]) {
            l=i,r=i;
        } else if(s[i]==s[l]) {
            cntt=i;
            xi=l;
            r=i;
        } else {
            r=i;
        }
        printf("%d %d\n",l,r);
    }
    return 0;
}