#include<iostream>
#include<algorithm>

using namespace std;

int a[1001];

int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
    {
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
    {
		sort(a+i,a+n);
		sum=sum+a[i]+a[i+1];
		a[i+1]=a[i]+a[i+1];
	}
	cout<<sum<<endl;
	return 0;
}

/*
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int main(){
    int i,N,x,Weight;
    while(scanf("%d",&N) != EOF){
        Weight = 0;
        //建立一个小顶堆
        priority_queue<int, vector<int>, greater<int> > MinHeap;
        //输入n个叶子节点的权值
        for(i = 0;i < N;i++){
            scanf("%d",&x);
            MinHeap.push(x);
        }
        //当堆中元素大于1
        while(MinHeap.size() > 1){
            //取出堆中最小的两个元素，他们同一个结点的左右儿子，且双亲结点的权值为他们的和
            int a = MinHeap.top();
            MinHeap.pop();
            int b = MinHeap.top();
            MinHeap.pop();
            //权值和
            Weight += a + b;
            MinHeap.push(a + b);
        }
        printf("%d\n",Weight);
    }//while
    return 0;
}
*/