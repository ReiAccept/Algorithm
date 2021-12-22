#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN=1e7+3;

namespace isprime6 {
    bool isprime(int a) {  //log_6^N isprime , 讲道理跑的飞快
        if(a==2||a==3) {
            return true;
        }
        if(a==1 || a%6!=1 && a%6!=5) {
            return false;
        }
        int temp=sqrt(a);
        for(int i=5;i<=temp;i+=6) {
            if(a%i==0||a%(i+2)==0) return false;
        }
        return true;
    }

    int work(int TARGET) {
        int cnt=0;
        for(int i=0;i<=MAXN;i++) {
            if(isprime(i)) {
                cnt++;
                if(cnt==TARGET) {
                    return i;
                }
            }
        }
        return -1;
    }   
}

namespace Eratosthenes { //Sieve of Eratosthenes 埃氏筛，复杂度为 O(Nlog(log(N)))
    int prime[MAXN+3],pcnt; //素数数组与素数的个数,prime[i]为第几个素数
    bool siv[MAXN+3]; //Sieve 筛子

    int work(int TARGET)  {
        for(int i=2;i<=MAXN;i++) {
            if(!siv[i]) {
                prime[++pcnt]=i;
                if(pcnt==TARGET) {
                    return i;
                }
                for(int j=i;i*j<=MAXN;j++) {
                    siv[i*j]=true;
                }
            }
        }
        return -1;
    }
}

namespace Liner { //线性筛（欧拉筛）复杂度为 O(N),1e8可用，基本上取代了埃氏筛
    int prime[MAXN+3],pcnt;
    bool siv[MAXN+3];

    int work(int TARGET)  {
        for(int i=2;i<=MAXN;i++) {
            if(!siv[i]) {
                prime[++pcnt]=i;
                if(pcnt==TARGET) {
                    return i;
                }
            }
            for(int j=1;j<=pcnt && i*prime[j]<=MAXN;j++) { //注意这个不是写在 if(!siv[i]) 里面的
                siv[i*prime[j]]=true;
                if(i%prime[j]==0) {
                    break;
                }
            }
        }
        return -1;
    }
}

namespace MillerRabin { //对 1e18 的超大素数判定 ,需要 #define int long long
    inline int fast_mul(int x,int y,int p) { //不快，防爆用
        return (__int128)x*y%p;
    }
    int fast_pow(int x,int y,int p) { //return x^y mod p
        long long ans=1;
        while(y) {
            if(y&1) {
                ans=fast_mul(ans,x,p);
            }
            x=fast_mul(x,x,p);
            y>>=1;
        }
        return ans;
    }
    bool isprime(int n) {
        if(n<=1) {
            return false;
        }
        static const int pr[]={2,3,5,7,11,13,17,19,23,29,31,37};
        for(auto a:pr) {
            if(n%a==0) {
                return n==a;
            }
        }
        int tmp=n-1,l=0;
        while((tmp&1)==0) { //和 tmp%2==0 相同
            tmp>>=1;
            l++;
        }
        for(auto a:pr){
            int x=fast_pow(a,tmp,n);
            if(x==1||x==n-1) {
                continue;
            }
            int j=0;
            while(++j<l){
                x=fast_mul(x,x,n);
                if(x==n-1) {
                    break;
                }
            }
            if(j>=l) {
                return false;
            }
        }
        return true;
    }
    int work(int TARGET) {
        int cnt=0;
        for(int i=0;i<=MAXN;i++) {
            if(isprime(i)) {
                cnt++;
                if(cnt==TARGET) {
                    return i;
                }
            }
        }
        return -1;
    }   
}

signed main() {
    cout<<isprime6::work(10001)<<endl;
    cout<<Eratosthenes::work(10001)<<endl;
    cout<<Liner::work(10001)<<endl;
    cout<<MillerRabin::work(10001)<<endl;
    return 0;
}