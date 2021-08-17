```cpp
#define int long long
int a,b;
const int up=2147483647;
signed main(){
    cin>>a>>b;
    if(a+b>up)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
```

```cpp
int T;
int y,m,d,ans;//年月日

bool leap(int yx) {//闰年
    if((yx%4==0 && yx%100) || yx%400==0) return true;
    return false;
}
signed main(){
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
```

```cpp
int T,n,l,r,opt;
int a[1003];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>T;
	while(T--) {
		cin>>l>>r>>opt;
		if(opt==1) sort(a+l,a+1+r);
		else sort(a+l,a+1+r,[](int a,int b){return a>b;});
		for(int i=l;i<=r;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
```

```cpp
int n;
int fib[30]={0,1,1};
bool a[100003];

signed main(){
    for(int i=3;i<=25;i++) fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<=25;i++) a[fib[i]]=true;
	while(cin>>n){
        if(a[n]) cout<<"Sakiya is so noob."<<endl;
		else cout<<"Hans_Moe is so dalao."<<endl;
    }
	return 0;
}
```

```cpp
int T,a,b;
signed main() {
	cin>>T;
	while (T--) {
		cin>>a>>b;
		cout<<(b-a)-(b/12-a/12)<<endl;
	}
	return 0;
}
```

```cpp
#define xx first
#define yy second
map<string, int> mp[23];
int n;
string s,t;
int main(){ 
    ios::sync_with_stdio(false);
    cin>>n>>s;
    mp[0][s] = 1;
    for(int i=1;i<=n;i++)
    for(auto it=mp[i-1].begin();it!=mp[i-1].end();++it)
    {
        t="";
        int len=(*it).xx.size();
        for(int i=0;i<len;i+=2) t+=(((*it).xx[i]-'0') | ((*it).xx[i+1]-'0'))+'0';
        mp[i][t]+=(*it).yy;
        t="";
        for(int i=0;i<len;i+=2) t+=(((*it).xx[i]-'0') & ((*it).xx[i + 1]-'0'))+'0';
        mp[i][t] += (*it).yy;
        t="";
        for(int i=0;i<len;i+=2) t+=(((*it).xx[i]-'0') ^ ((*it).xx[i + 1]-'0'))+'0';
        mp[i][t]+=(*it).yy;
    }
    cout<<mp[n]["1"]<<endl;
    return 0;
}
```
