#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int a[200003];
string s;

void work()
{
    int n=read(),last=0,top=0,cur=1;
    cin>>s;
    for(int i=1;i<n;i++) if(s[i]!=s[i-1]) a[++top]=i-last,last=i;
    a[++top]=n-last;
    for(int i=1;i<=top;i++)
    {
        while(cur<=top && a[cur]==1) cur++;
        //cur用来记录上一次操作中长度大于1的连续字段的下标 
        a[cur]--;
        if(cur>top)
        {
            cout<<i-1+(top-i+2)/2<<endl;
            return;
        }
        if(cur<=i)cur=i+1;
    }
    cout<<top<<endl;
    return;
}

signed main()
{
    int T=read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
//每次删除任意一个字符,删除最前面的连续字段。

/*
而如果0/1在某些地方连续出现了多次
我们在删去这些连续的字段之前贪心地把删除单个字符的操作放在这些字段里肯定是最优的。
由于我们只关心连续字段的长度,因此可以开一个数组记录每个字段的长度,对于每次操作,先删掉任意一个还未被删去的连续字段中的一个字符,再删去最前面的连续字段。
前者具有单调性,维护一下就可做到 O(n) 的复杂度。
 */
