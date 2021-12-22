#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e6+3;

char s[7][MAXN];
char hb[10]="harbin";
int n[6];
map<char,int> m[10];
int num[7][7];
void work() {
    for(int i=0;i<7;i++) {
        m[i].clear();
    }
    for(int i=0;i<6;i++) {
        scanf("%s",s[i]);
        n[i]=strlen(s[i]);
        for(int j=0;j<n[i];j++) {
            m[i][s[i][j]]++;
        }
    }
    sort(hb,hb+6);
    do {
        bool flag2=false;
        for(int i=0;i<6;i++) {
            if(!m[i][hb[i]]) {
                flag2=true;
                break;
            }
        }
        if(!flag2) {
            printf("Yes\n");
            return;
        }
    }while(next_permutation(hb,hb+6));
    printf("No\n");
    return;
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}

// harbin

/*
h
b
a
r
i
n
*/