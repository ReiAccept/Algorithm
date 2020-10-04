#include <bits/stdc++.h>
using namespace std;
int n,k,tmp,a[2009],ans[2009],cnt=0,b[2009],len,sum=0;
int Next[2009],now=0;
 
bool cmp(int a,int b){return a<b;}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
		a[i]=b[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>n-k;i--){
        ans[++cnt]=a[i];
        sum+=a[i];
        Next[cnt]=cnt+1;
	}
    printf("%d\n",sum);
    for(int i=1;i<=n;i++){
        len++;
        for(int j=1;j<=cnt;j=Next[j]){
            if(ans[j]==-1)continue;
            if(ans[j]==b[i]){
                now++;
                if(now==k){
                    printf("%d\n",n-i+len);
                    i=n+1;
                    break;
                }
                printf("%d ",len);
                sum-=a[j];
                ans[j]=-1;len=0;
                break;
            }
        }
    }
	return 0;
}
