# Codeforces 596 C Wilbur and Points

*原文*  [http://blog.csdn.net/yp_2013/article/details/50532724](javascript:void())

传送门：
[http://codeforces.com/contest/596/problem/C](javascript:void())

题意：
给n个点的坐标，然后让你重新排序，规则是x,y坐标均小的要排在前面，规则具体看题即可，使得点的权值w[i]与给出的序列吻合，如果存在该序列则输出，否则输出NO

思路：
冥想阶段：
肯定是排序，然后再判断一下给出的这种方案合法否么，粗略的想法就是把w的值从小到大排序，那么点的排序方法必定就是右端点从小到大，相同的话左端点就是从大到小嘛，然后看是不是吻合，如果吻合就按照w的id值输出 ，
w的顺序已经变了，所以说只要w的id 值去放答案就ok了
丫的，还是题意理解错了，题目说的是最后给出的序列要满足那个w值的条件，而按我上面给出的做法，最后再按照编号分配答案的话就没有什么意义了，完全是错的了！！！
冥想结束！！！

题意还是应该正着读并且反着读还要多读，题目中说的是大于等于x的并且大于等于y的点的编号一定不比这个点小
而我理解理解就变成了小于等于x并且小于等于y的点的编号一定要比这个点小，其实这二者之间的逻辑并不是一样的 ，就是应该多回去读几遍题意，否则就被自己意会的题意给带偏了

那么既然是这个样子的话，下面的解法就很理所应当了，因为题目里保证了小于等于x并且小于等于y的点一定都在输入当中

看到了一个很牛B的做法，使用set来解决掉的，其实这道题就是贪心就可以构造出解，即每次取出对应k值得x,y小的那个，填入就行了，至于怎么判断不行呢，那就是如果之前的数里面没有（x,y-1）和（x-1,y）呢，就是肯定不行的，因为它会保证这些点肯定存在，那么它就一定是在这个点的后面了，那么上面的点的编号就比它要小了，就不满足题意了！！！
所以先上上这份逼格较高的set解法
之所以要用set去解，还是因为写起来方便，否则会很麻烦，思路很简单，用上高端一点的数据结构去接就更完美不过了！！！！！
再仔细反思一下，其实刚开始没有想到这种解法的原因就是被样例给带偏了，没有想到这种贪心的方法，同时读到那句保证之前的数字都出现在input中的时候也没有认真去想内含是什么

还要特别注意数据结构中两个.连用的情况，不改成->的话，编译器会分不清顺序，即不识别是谁.谁，然后就会导致报错！！！！！

还算优美的写法：

```
#include<bits/stdc++.h>
using namespace std;
const int mod=1e5;
const int maxn=2e5+10;
typedef pair<int,int>pp;
set<pp>s[maxn],pre;
vector<pp>ans;
int n,x,y,k;
int check(){
    for(int i=1;i<=n;i++){
        scanf("%d",&k);k+=mod;
        if(s[k].size()==0) return 0;//miss this warn
        int xx=s[k].begin()->first;
        int yy=s[k].begin()->second;
        s[k].erase(s[k].begin());
        if(xx&&!pre.count({xx-1,yy})) return 0;
        if(yy&&!pre.count({xx,yy-1})) return 0;
        pre.insert({xx,yy});
        ans.push_back({xx,yy});
    }
    return 1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        s[y-x+mod].insert({x,y});
    }
    if(check()){
        puts("YES");
        for(int i=0;i<n;i++){
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    } 
    else puts("NO");
    return 0;
}
```