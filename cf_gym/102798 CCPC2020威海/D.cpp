#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int read() {
    int x; scanf("%lld",&x); return x;
}
const int S=8;
long long mult_mod(int a,int b,int c)
{
    a%=c; 
    b%=c;
    int ret=0;
    int tmp=a;
    while(b) {
        if(b&1){
            ret+=tmp;
            if(ret>c) ret-=c;
        }
        tmp<<=1;
        if(tmp>c)tmp-=c;
        b>>=1;
    }
    return ret;
}

int pow_mod (int a,int n,int mod)
{
    int ret=1;
    int temp=a%mod;
    while(n){
        if(n&1) ret=mult_mod(ret,temp,mod);
        temp=mult_mod(temp,temp,mod);
        n>>=1;
    }
    return ret;
}
bool check(int a,int n,int x,int t)
{
    int ret=pow_mod(a,x,n);
    int last=ret;
    for(int i=1;i<=t;i++){
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;
        last=ret;
    }
    if(ret!=1) return true;
    else return false;
}
bool Miller_Rabin(int n){
    if(n<2) return false;
    if(n==2) return true;
    if((n&1)==0) return false;
    int x=n-1;
    int t=0;
    while((x&1)==0) {x>>=1; t++;}
    srand(time(NULL));
    for(int i=0;i<S;i++){
        int a=rand()%(n-1)+1;
        if(check(a,n,x,t)) return false;
    }
    return true;
}
int factor[5000];
int tol;
int gcd(int a,int b)
{
    int t;
    while(b){
    t=a;
    a=b;
    b=t%b;
    }
    if(a>=0) return a;
    else return -a;
}

int pollard_rho(int x, int c){
    int i=1, k=2;
    srand(time(NULL));
    int x0=rand()%(x-1)+1;
    int y=x0;
    while(1){
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        int d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k) {
            y=x0; k+=k;
        }
    }
}
void findfac(int n,int k)
{
    if(n==1) return;
    if(Miller_Rabin(n))
    {
        factor[tol++] =n;
        return;
    }
    int p=n;
    int c=k;
    while(p>=n)
    {p=pollard_rho(p,c--);}
    findfac(p,k);
    findfac(n/p,k);
}

void work() {
    n=read();
    if(Miller_Rabin(n)) printf("no\n");
    else {
        tol=0;
        findfac(n,107);
        sort(factor,factor+tol);
        int p=tol;
        int m=unique(factor,factor+tol)-factor;
        if(m<p) printf("yes\n");
        else printf("no\n");
    }
}

signed main() {
    int T=read();
    for(int CASE=1;CASE<=T;CASE++) {
        work();
    }
    return 0;
}