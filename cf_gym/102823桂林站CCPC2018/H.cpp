#include<bits/stdc++.h>
#define int long long

using namespace std;

int read() {
    int x; scanf("%lld",&x); return x;
}

const int MAXN=1e4+3;

char s1[MAXN],s2[MAXN],ans[MAXN],ans2[MAXN];
int sum[MAXN];

// void work(int CASE) {
//     scanf("%s%s",s1+1,s2+1);
//     int n=strlen(s1+1),cnt=0;
//     // memset(sum,0,sizeof(sum));
//     int a1=0,a2=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(s1[i]=='a')a1++;
//         if(s2[i]=='a')a2++;
//     }
//     // cout<<a1<<" "<<a2<<endl;
//     if(a1==a2)
//     {
//         printf("Case %lld: ",CASE);
//         for(int i=1;i<=n;i++)printf("a");
//         printf("\n");
//         return;
//     }
//     if(a1<a2)
//     {
//         swap(s1,s2);
//         swap(a1,a2);
//     }
    
//     cnt=a1-a2;
//     for(int i=n;i>=1;i--)
//     {
//         if(cnt==0||s1[i]==s2[i])
//         {
//             ans[i]='a';
//             continue;
//         }
//         if(s1[i]=='a')
//         {
//             cnt--;
//             if(cnt>0)
//             {
//                 ans[i]=s2[i];
//                 cnt--;
//             }
//             else 
//             {
//                 for(char c='a';c<='z';c++)
//                 {
//                     if(s1[i]!=c&&s2[i]!=c)
//                     {
//                         ans[i]=c;
//                         break;
//                     }
//                 }
//             }
//         }
//         else if(s2[i]=='a')
//         {
//             ans[i]=s2[i];
//         }
//         else{
//             ans[i]=s2[i];
//             cnt--;
//         }
//     }
//     printf("Case %lld: ",CASE);
//     for(int i=1;i<=n;i++) {
//         printf("%c",ans[i]);
//     }
//     printf("\n");
//     return;
// }

void work2(int CASE) {
    scanf("%s%s",s1+1,s2+1);
    int n=strlen(s1+1),cnt=0;
    memset(sum,0,sizeof(sum));
    for(int i=n;i>=1;i--) {
        sum[i]=sum[i+1];
        if(s1[i]!=s2[i]) {
            sum[i]++;
        }
    }
    for(int i=1;i<=n;i++) {
        for(char c='a';c<='z';c++) {
            if(s1[i]!=c) cnt++;
            if(s2[i]!=c) cnt--;
            if(abs(cnt)<=sum[i+1]) {
                ans2[i]=c;
                break;
            }
            if(s1[i]!=c) cnt--;
            if(s2[i]!=c) cnt++;
        }
    }
    printf("Case %lld: ",CASE);
    for(int i=1;i<=n;i++) {
        printf("%c",ans2[i]);
    }
    printf("\n");
    return;
}

void make() {
    // srand(time(NULL));
    int n=10;
    for(int i=1;i<=n;i++) {
        s1[i]='a' + rand()%26;
        s2[i]='a' + rand()%26;
    }
    printf("TESTS1:%s\n",s1+1);
    printf("TESTS2:%s\n",s2+1);
}

signed main() {
    int T=read();
    // int T=1;
    // getchar();
    for(int CASE=1;CASE<=T;CASE++) {
        // make();
        // work(CASE);
        work2(CASE);
    }
    return 0;
}
/*
TESTS1:zyqwqyosvhkwzwhanzeyaojlcxqfkyoxjddgqjkvjxfmigsezkawpzbrlbzptrsbwgcdiduav
TESTS2:iaanjxohkdjawscbnbittlvpuayfekhmzvlalnkcpjudbzuxkditnovimugemqzbmtdhuniid

TESTS1:hgueynfxicsxgwfquwnovrkpegxprytwyycpvkfmn
TESTS2:qhmalldfrvcgbkndxffzstjrpgrnvsmcsyqeiefzi

TESTS1:qmujovouwm
TESTS2:pxjloawxhs
*/