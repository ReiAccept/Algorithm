#include<bits/stdc++.h>

using namespace std;

int point;
int a,b;
string s;
vector<int> p[10];

// map<string,pair<int,int> > m;

void work() {
    cin>>a>>b;
    cin>>s;
    for(int i=(int)s.size()-1;i>=0;i--) {
        // if(s[i]=='.') {
        //     point=i;
        //     break;
        // }
        if(s[i]=='.') {
            break;
        }
        p[s[i]-'0'].push_back(i);
    }
    // int r=(int)s.size()-point-1;
    // printf("%d\n",(a-1)*r-b*(r-1)+r);
}

signed main() {
    signed T=1;
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}