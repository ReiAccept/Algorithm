#include<bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x,0,sizeof(x))
#define mmst3f(x) memset(x,0x3f,sizeof(x))
#define si(x) scanf("%d",&x)//scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("Yes\n")
#define NOO printf("No\n")
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF=0x3f3f3f3f;//0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN=(int)5e5+3;

inline char nc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
inline int read(){int s=0,w=1;char ch=nc();while(!isdigit(ch)){if(ch=='-')w=-1;ch=nc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=nc();} return s*w;}
//inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
// inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9')) ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} // 根据参数个数自动选择
// void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

int s[MAXN];
char op[20];
deque<int >q;
bool isrev;
int t,n,r=250001,l=250000,sum;

void PUSH() {
    int a;
    scanf("%d",&a);
    if(isrev) {
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
    sum++;
}

void POP() {
    if(sum==0)
        return;
    if(isrev) {
        if(s[r-1]==0)
            q.pop_back();
        r--;
    } else {
        if(s[l+1]==0)
            q.pop_front();
        l++;
    }
    sum--;
}

void QRY() {
    int cur=0;
    if(sum==0) {
        cout<<"Invalid."<<endl;
        return;
    } else if(sum==1) {
        cout<<s[l+1]<<endl;
        return;
    }
    if(isrev) {
        if(q.empty())
            cur=sum;
        else {
            cur=q.front()==r-1?sum-1:q.front()-l;
        }
    } else {
        if(q.empty())
            cur=sum;
        else {
            cur=q.back()==l+1?sum-1:r-q.back();
        }
    }
    printf("%d\n",cur%2);
}

inline void work(signed CASE=1,bool FINAL_CASE=false) {
        memset(s,-1,sizeof s);
        scanf("%d",&n);
        r=250001,l=250000,sum=0,isrev=true;
        q.clear();
        while(n--) {
            scanf("%s",op);
            if(op[0]=='P'&&op[1]=='U') {
                PUSH();
            } else if(op[0]=='P'&&op[1]=='O') {
                POP();
            } else if(op[0]=='Q') {
                QRY();
            } else {
                isrev^=1;
            }
        }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
    signed T=1;//(signed)read();//
    scanf("%d",&T);//cin>>T;
    for(signed CASE=1; CASE<=T; CASE++) { //
        //printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //
        printf("Case #%d:\n",CASE); //printf("Case %d: \n",CASE);
        //while(cin>>n) work(n);
        work(CASE,CASE==T);
    }
    return 0;
}
