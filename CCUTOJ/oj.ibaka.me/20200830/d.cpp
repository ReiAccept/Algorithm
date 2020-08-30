#include<bits/stdc++.h>

using namespace std;

int n,t;

bool isPrime3(int n){//模板素数判断
 bool yes=false;
 if(n==2||n==3||n==5){ //当n<6时列举即可
  yes=true;
 }
 else if(n%6==1||n%6==5){ //通过判断余数的方式来判断n的表达式
  yes=true;
  for(int i=2;i<=sqrt(n);i++){
   if(n%i==0){
    yes=false;
    break;
   }
  }
 }
 return yes;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<7)
        {
            if(n==1 || n==2 || n==3 ||n==5 || n==7)printf("1\n");
            else printf("0\n");
        }
        else
        {
            if(isPrime3(n)) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
