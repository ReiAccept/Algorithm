#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}

int n,k,flag;
queue<int> q;
set<int> idx;
struct Node
{
    int nl,i;
}a[200003];

void work()
{
	n=read();k=read();
	for(int i=0;i<n;i++) a[i].nl=read(),a[i].i=i;
	sort(a,a+n,[](Node a,Node b){return a.nl>b.nl;});
	for(int i=0;i<n;i++) q.push(a[i].i);
	for(int i=0;i<n;i++) idx.insert(i);
	string ans(n,'1');
	while (!idx.empty()) 
    {
		while(!idx.count(q.front()))q.pop();
		int pos=q.front();
		q.pop();
		vector<int> add;
		auto it=idx.find(pos);
		for(int i=0;i<=k;i++) 
        {
			add.push_back(*it);
			if (it==idx.begin()) break;
			it--;
		}
		it=next(idx.find(pos));
		for(int i=0;i<k;i++) 
        {
			if (it==idx.end()) break;
			add.push_back(*it);
			it++;
		}
		for(auto it : add)
        {
			idx.erase(it);
            if(flag) ans[it]='2';
		}
		flag=!flag;
	}
	cout<<ans<<endl;
    return;
}

signed main()
{
    int T=1;//read();
	for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
