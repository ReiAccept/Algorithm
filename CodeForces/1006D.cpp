#include <bits/stdc++.h>
using namespace std;
int n,tmp,ans;
char a[100009],b[100009];
int read(){
    char ch;
    while(ch=getchar(),ch<'0'||ch>'9');tmp=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9')tmp=tmp*10+ch-'0';
    return tmp;
}
int main()
{
	n=read();
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n/2;i++){
        if(b[i]==b[n-i+1]){
            if(a[i]!=a[n-i+1])ans++;
            continue;
        }
        if(a[i]==b[i]){
            if(a[n-i+1]==b[n-i+1])continue;
            ans++;
            continue;
        }
        if(a[i]==b[n-i+1]){
            if(a[n-i+1]==b[i])continue;
            ans++;
            continue;
        }
        ans++;
        if(a[n-i+1]==b[n-i+1]||a[n-i+1]==b[i])continue;
        ans++;
	}
	if((n&1)&&a[(n+1)/2]!=b[(n+1)/2])
        ans++;
	printf("%d",ans);
	return 0;
}
