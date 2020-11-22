#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

FILE *in;

void do_it(int x);
void find_title();
void find_problem();

//主函数,程序入口,打开题目的输出文件；
//采用for循环使x增加,重复调用do_it(x),x为题目编号。
int main()
{
    freopen("problem.txt","r",stdout);
    int x=1000;
    for(;x<=1657;x++)
        do_it(x);
    return 0;
}

//x为当前需要匹配的题目编号,
//文件名为"showproblem-problem_id="x".html"
void do_it(int x)
{
    in=fopen("showproblem-problem_id=1600.html","r"); //仅测试，改为多个文件批量读取
    void find_title();
}

//寻找题目标题的函数,题目标题在HTML的"<title>"与"</title>"包围中
//通过匹配HTML标记,记录下标记所在数组下标并取中间部分输出。
void find_title()
{
    char title_begian[]="<title>";
    char title_end[]="</title>";
    vector<char> art;
    art.clear();
    
    string v1;
    int sz,sz_beg,sz_end,n;
    cin>>v1;
    sz=v1.length();
    sz_beg=7;
    sz_end=8;
    for(int i=0;i<sz;i++)
    {   
        int t=i;
        n=0;
        for(int k=0;k<sz_beg;k++)
        {
            if(title_begian[k]!=v1[t])
                break;
            t++;
            n++;
            if(n==sz_beg)
            {
                cout<<++i<<endl;
                return;
            };
        }
    }
}