#include<bits/stdc++.h>
using namespace std;
const int N=50;
int a[N],b[N],up[N],down[N];
int t;
int main()
{
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        for(int i=0;i<=3;i++) {
            a[i]=s[i]-'0';
        }
        cin>>s;
        for(int i=0;i<=3;i++) {
            b[i]=s[i]-'0';
        }
        for(int i=0;i<4;i++) {
            up[i]=a[i]-b[i];
            if(up[i] < 0) up[i] += 10;
            down[i]=(10-up[i])%10;
         }
        // for(int i=0;i<4;i++) {
        //     cout<<up[i]<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
        // for(int i=0;i<4;i++) {
        //     cout<<down[i]<<" ";
        // }
        // cout<<endl;
        int ans=1e9;
        // int p[10]={0,0,0,0,1,1,1,1};
        // do 
        // {
        //     // for(int i=0;i<=3;i++) {
        //     //     cout<<p[i]<<" ";
        //     // }
        //     // cout<<endl;
        //     int cnt=0;
        //     for(int i=0;i<=3;) {
        //         int k=p[i];
        //         while(p[i]==k&&i<=4) i++;
        //         int pp=0;
        //         if(k==0)
        //         {
        //             pp=0;
        //             for(int j=0;j<i;j++) {
        //                 pp=max(up[j],pp);
        //             }
        //         }else {
        //             pp=0;
        //             for(int j=0;j<i;j++) {
        //                 pp=max(down[j],pp);
        //             }
        //         }
        //         cnt += pp;
        //         // i--;
        //         // cout<<"i="<<i<<endl;  
        //     }
        //     ans=min(ans,cnt);
        // }while(next_permutation(p,p+8));
        int cnt=0;
        for(int i=0;i<4;i++) cnt=max(cnt,up[i]);
        ans=min(ans,cnt);
        cnt=0;
        for(int i=0;i<3;i++) cnt=max(cnt,up[i]);
        cnt+=down[3];
        ans=min(ans,cnt);
        cnt=0;
        cnt=max(up[0],up[1])+down[2]+up[3];
        ans=min(ans,cnt);
        cnt=0;
        cnt=max(up[0],up[1])+max(down[2],down[3]);
        ans=min(ans,cnt);
        cnt=0;
        cnt=up[0]+down[1]+max(up[2],up[3]);
        ans=min(ans,cnt);
        cnt=0;
        cnt=up[0]+down[1]+up[2]+down[3];
        ans=min(ans,cnt);
        cnt=0;
        cnt=up[0]+max(down[1],down[2])+up[3];
        ans=min(ans,cnt);
        cnt=0;
        cnt=up[0]+max(down[1],max(down[2],down[3]));
        ans=min(ans,cnt);
        cnt=0;
        cnt=down[0]+max(up[1],max(up[2],up[3]));
        ans=min(ans,cnt);
        


        cout<<ans<<endl;
    }
    return 0;
}
