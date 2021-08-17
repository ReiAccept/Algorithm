#include <cstdio>
#include<stack>

using namespace std;

int n,a[1005];
int flag,start;//flag标记位,start起始位
bool result=true;

stack<int> s;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(flag<n)
    {
        if(start==a[flag])
        {
            start++;
            flag++;
        }
        else if(!s.empty() && s.top()==a[flag] )
        {
            s.pop();
            flag++;
        }
        else if(start<=n)
        {
            s.push(start++);
        }
        else
        {
            result=false;
            break;
        }
    }

    if(result)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}


/*
#include<iostream>//写的C++代码
#include<stack>//调用堆栈
using namespace std;//使用标准命名空间
int main()
{
    int n,target[100];//定义数组
    cin>>n;
    for(int i=1; i<=n; i++) //从键盘输入火车出站可能性
    {
        cin>>target[i];//输入到出站目标数组中，也就是1...n可能的出站顺序
    }
    int A=1,B=1;//A是起始1....n火车入站的起始位置，B是坐标
    stack<int> s;//定义一个堆栈
    int ok=1;//标志位，是否可能出现这种出站顺序
    while(B<=n)//标志位没有超过最大值
    {
        if(A==target[B]) //如果第一个目标就是火车入口第一辆的话，那么它就是进站立刻出站，这种可能性需要
        {
            A++;
            B++;//增加A让下一辆准备，增加B第一个目标满足，第二个目标准备
        }
        else if(!s.empty()&&s.top()==target[B] )  //如果站不为空，并且站顶等于目标则，让目标增加，并让这个站里的火车出站
        {
            s.pop();
            B++;
        }
        else if(A<=n)
        {
            s.push(A++);//如果起始要小于n也就是起始位置还有活着，那么遍历一次后就需要下一个火车进站
        }
        else   //如果起始站点没有火车了，B还没收到所有火车，这时，不能有此种输出顺序。
        {
            ok=0;
            break;
        }
    }
    if(ok) //开始输出，如果可能B收到所有火车，这时火车可能以这种方式出站，否则不可能，一下是可能的输出结果截图
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
*/
