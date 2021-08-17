#include<bits/stdc++.h>

using namespace std;

int T;
int y,m,d,ans;//年月日

bool leap(int yx) {//闰年
    if((yx%4==0 && yx%100) || yx%400==0) return true;
    return false;
}

signed main()
{
    cin>>T;
    while(T--) {
        scanf("%d-%d-%d", &y, &m, &d);
        if(m==2 && d==29 && (!leap(y+18))) cout<<-1<<endl;
        else {
            ans=365*18;
            for(int i=1; i<18; i++) ans+=leap(y+i);
            if(m>2) ans+=leap(y+18);
            else if(m<2 || d!=29) ans+=leap(y);
            cout<<ans<<endl;
        }
    }
    return 0;
}
