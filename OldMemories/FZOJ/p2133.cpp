#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node 
{
	int start, end, num;
	Node(int s,int e,int h):start(s),end(e),num(h){}//构造函数
};

bool cmp(Node a,Node b)
{
	return a.end < b.end;
}

vector<Node> nodes;
int n, m, ans;
bool flag[50005];//i是否种了树

int main() 
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) 
	{
		int s,e,h;
		scanf("%d%d%d",&s,&e,&h);
		nodes.push_back(Node(s,e,h));
	}
	sort(nodes.begin(),nodes.end(),cmp);
	for(int i=0;i<m;i++) 
	{
		int tmp=0;//当前已经种了多少棵树,与需要种的数量是否相等
		for(int j=nodes[i].start;j<=nodes[i].end;j++) 
		{
			if(flag[j])
				tmp++;
			if(tmp==nodes[i].num)
				break;
		}
		if(tmp<nodes[i].num) 
			for(int j=nodes[i].end;j>=nodes[i].start;j--)
				if(!flag[j]) 
				{
					flag[j]=true;
					tmp++;
					ans++;
					if(tmp==nodes[i].num) 
						break;
				}
	}
	printf("%d\n", ans);
	return 0;
}
