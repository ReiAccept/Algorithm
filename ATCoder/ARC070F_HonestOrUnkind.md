# ARC070F HonestOrUnkind

### 直接去luogu看翻译版好了

https://www.luogu.com.cn/problem/AT2348

query函数就直接贴luogu题面给的那个就行

### Solution

当a<=b时，可以有a个unkind的人假装自己就是那a个honest的人。（彼此之间都说是honest的，说别人都是unkind的）所以直接特判a<=b的情况就行

首先可以看出一个结论就是如果有人说另一个人unkind，那这两个人之间一定至少有一个人是unkind的，那么这两人都让他们爬，直接都不考虑的情况下，依旧a>b(a-1,b-1或者a,b-2)

依次枚举每一个人(就? 01  ? 12  ?23这样问)，询问栈顶当前枚举的点是否是诚实的(栈为空的时候就入栈)

回答有两种情况，honest的，入栈，unkind的，出栈。

显然是O(n)的复杂度（对这个题够了）



还有一个神仙一点的做法依赖于数学技巧，复杂度是O(nα(n)) https://www.cnblogs.com/cly-none/p/9021812.html 这方法太神仙了

