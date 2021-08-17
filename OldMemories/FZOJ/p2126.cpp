#include<cstdio>
#include<iostream>

using namespace std;

string a,b;
int ans,flag;

int main()
{
	//freopen("2126.in","r",stdin);
	//freopen("2126.ans","w",stdout);
	ios::sync_with_stdio(false);
	while(true){
		cin>>a;
		if(a!="#")
		{
			flag=ans=0;
			cin>>b;
			while(true)
			{
				flag=a.find(b,flag);
				if(flag!=-1)
				{
					ans++;
					flag+=b.size();
				}
				else
					break;
			}
			cout<<ans<<endl;
		}
		else
			break;
	}
	return 0;
}


/*
#include <stdio.h>
#include <string.h>
#define SIZE 1100
 
char t[SIZE] , des[SIZE] ;
int next[SIZE] ;
 
void getNext()
{
	int len = strlen(t) ;
	int i = -1 , j = 0 ;
	next[0] = -1 ;
	while(j<len)
	{
		if(i == -1 || t[i] == t[j])
		{
			++i,++j;
			next[j] = i ;
		}
		else
		{
			i = next[i] ;
		}
	}
}
 
int kmp()
{
	int i = 0 , j = 0 ;
	int len1 = strlen(t) , len2 = strlen(des) ;
	int c = 0 ;
	getNext() ;
	while(j<len2)
	{
		if(i == -1 || t[i] == des[j])
			++i ,++j;
		else
			i = next[i] ;
		if(i == len1)
		{
			i = 0 ;
			c++ ;
		}	
	}
	return c ;
}
 
int main()
{
	while(~scanf("%s",des) && strcmp(des,"#")!=0)
	{
		scanf("%s",t) ;
		int ans = kmp() ;
		printf("%d\n",ans) ;
	}
	return 0  ;
}
*/
