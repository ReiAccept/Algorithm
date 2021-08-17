```cpp
int n,m;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m-(n%m);i++) cout<<n/m<<" ";
    for(int i=1;i<=n%m;i++) cout<<(n/m)+1<<" ";
    return 0;
}
```

```cpp
int n,q,k;
int a[1003];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cin>>q;
    while(q--){
        cin>>k;
        cout<<a[k]<<endl;
    }
    return 0;
}
```

```cpp
int n,m,d,w,h,x,y;
char g[33][33];
string route;
inline int chk(int xr,int yr){
    if(g[xr][yr]=='P') return w;
    return 0;
}
signed main(){
    cin>>n>>m>>d>>w;
    for(int i=0;i<n;i++) cin>>g[i];
    while(d--){
        cin>>h>>x>>y>>route;
        int dmg=chk(x,y);
        for(int i=0;i<(int)route.size();i++){
            if(route[i]=='W') dmg+=chk(--x,y);
            else if(route[i]=='S') dmg+=chk(++x,y);
            else if(route[i]=='A') dmg+=chk(x,--y);
            else if(route[i]=='D') dmg+=chk(x,++y);
        }
        if(dmg>=h) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
```

```cpp
int n;
int a[4];
int main(){
    while(cin>>n){
        cin>>a[1]>>a[2]>>a[3]; int r=(a[1]%2)+(a[2]%2)+(a[3]%2);
        if(r==0){ //all even
            for(int tmp,i=4;i<=n;i++){
                cin>>tmp;
                if(tmp%2) cout<<tmp<<endl;
            }
        }
        else if(r==1){ //only one add
            for(int i=1;i<=3;i++) if(a[i]%2) cout<<a[i]<<endl;
            for(int tmp,i=4;i<=n;i++) cin>>tmp;
        }
        else if(r==2){ //only one even
            for(int i=1;i<=3;i++) if(a[i]%2==0) cout<<a[i]<<endl;
            for(int tmp,i=4;i<=n;i++) cin>>tmp;
        }
        else{//all odd
            for(int tmp,i=4;i<=n;i++){
                cin>>tmp;
                if(tmp%2==0) cout<<tmp<<endl;
            }
        }
    }
    return 0;
}
```

```cpp
#define int long long
const int mod=1000000007;
int n,k,l,r;
int sum[100003];
int f[100003][2]={1};
signed main(){
    cin>>n>>k;
    for(int i=1;i<=100000;i++){
        f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
        if(i>=k) f[i][1]=f[i-k][0]%mod;
        sum[i]=(sum[i-1]+f[i][1]+f[i][0])%mod;
    }
    while(n--){
        cin>>l>>r;
        cout<<(sum[r]-sum[l-1]+mod)%mod<<endl;
    }
    return 0;
}
```

