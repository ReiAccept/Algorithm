#include<iostream>

using namespace std;

int n,res;
int s[103],a[103],b[103];

int main()
{
    cin>>n;
    //for(int i=0;i<str.size();i++){s[i+1]=str[i]-'0';res+=s[i+1];}
    for(int i=1;i<=n;i++){
        char tmp;
        cin>>tmp;
        if(tmp=='1')s[i]=true;
        if(s[i]) res++;
    }
    if(res==n){cout<<n<<endl;return 0;}
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int t=1,now=res;t<=10000;t++){
        for(int i=1;i<=n;i++){
            if(t==b[i]){
                if(s[i]) now-=1;
                else now+=1;
                s[i]^=1;
                b[i]+=a[i];
            }
        }
        if(now>res) res=now;
        if(res==n){cout<<n<<endl;return 0;}
    }
    cout<<res<<endl;
    return 0;
}

/*
struct L{
    int a,b;
}l[103];

int n,ans,cur;
bool s[103],s2[103];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        char tmp;
        cin>>tmp;
        if(tmp=='1')s[i]=true;
        s2[i]=s[i];
        if(s[i]) ans++;
    }
    if(ans==n){cout<<n<<endl;return 0;}
    cur=ans;
    for(int i=1;i<=n;i++) cin>>l[i].a>>l[i].b;
    for(int i=1;i<=50000;i++){
        for(int j=1;j<=n;j++){
            int a=l[j].a,b=l[j].b;
            if((i-b==0) || ((i-b)%a==0)){
                s[j]=!s[j];
                if(s[j]) cur++;
                if(!s[j]) cur--;
            }
        }
        if(cur>ans) ans=cur;
        //for(int i=1;i<=n;i++){cout<<s[i];}cout<<endl;
        if(ans==n){cout<<n<<endl;return 0;}
    }
    cout<<ans<<endl;
    return 0;
}
*/
