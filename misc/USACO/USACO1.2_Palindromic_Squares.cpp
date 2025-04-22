/*
ID:sa128471
PROG:palsquare
LANG:C++
*/
#include<iostream>
#include<cstdio>
using namespace std;
int B;
const
  int MAX=300;
  char CH[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
 
void printdata(int x)
{
  int a[30],i=0;
  while (x>0) a[++i]=x%B,x/=B;
  for(;i;cout<<CH[ a[i--] ]);
}
 
void handle( int x )
{
  int a[30],n=0,xx=x*x;
  while (xx>0)  a[++n]=xx%B,xx/=B;
  int t=n;
  for(;(n>0)&&(a[n]==a[t-n+1]);--n);
  if (n==0) printdata(x),cout<<' ',printdata(x*x),cout<<endl;
}
 
int main()
{ 
  freopen("palsquare.in","r",stdin);
  freopen("palsquare.out","w",stdout);
  cin>>B;
  for(int i=1;i<=MAX;i++) handle(i);
  return 0;
}