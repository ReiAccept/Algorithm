#include<bits/stdc++.h>
#define MAXN 500000
using namespace std;
int s[MAXN];
char op[20];
deque<int >q;
int t,n,r=250001,l=250000,fa=0,f=1,Case=1;

void PUSH() {
    int a;
    scanf("%d",&a);
    if(f) {
        s[r]=a;
        if(!a)
            q.push_back(r);
        r++;
    } else {
        s[l]=a;
        if(!a)
            q.push_front(l);
        l--;
    }
    fa++;
}

void POP() {
    if(!fa)
        return;
    if(f) {
        if(s[r-1]==0)
            q.pop_back();
        r--;
    } else {
        if(s[l+1]==0)
            q.pop_front();
        l++;
    }
    fa--;
}

void QRY() {
    int cur=0;
    if(fa==0) {
        cout<<"Invalid."<<endl;
        return;
    } else if(fa==1) {
        cout<<s[l+1]<<endl;
        return;
    }
    if(f) {
        if(q.empty())
            cur=fa;
        else {
            cur=q.front()==r-1?fa-1:q.front()-l;
        }
    } else {
        if(q.empty())
            cur=fa;
        else {
            cur=q.back()==l+1?fa-1:r-q.back();
        }
    }
    printf("%d\n",cur%2);
}

int main() {
    scanf("%d",&t);
    while(t--) {
        memset(s,-1,sizeof s);
        scanf("%d",&n);
        r=250001,l=250000,fa=0,f=1;
        q.clear();
        printf("Case #%d:\n",Case++);
        while(n--) {
            scanf("%s",op);
            if(op[0]=='P'&&op[1]=='U') {
                PUSH();
            } else if(op[0]=='P'&&op[1]=='O') {
                POP();
            } else if(op[0]=='Q') {
                QRY();
            } else {
                f^=1;
            }
        }
    }
    return 0;
}
