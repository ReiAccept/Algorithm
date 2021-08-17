#include<iostream>

using namespace std;

string s1,s2;

void finds(string sbe,string saf)//s_before s_after
{
    if(sbe.size()<=0) return;
    char c=saf[saf.size()-1];
    cout<<c;
    long unsigned int n=sbe.find(c);
    finds(sbe.substr(0,n),saf.substr(0,n));
    finds(sbe.substr(n+1),saf.substr(n,saf.size()-n-1));
    //递归时丢弃掉已找到的c
}

int main()
{
    cin>>s1>>s2;
    finds(s1,s2);
    return 0;
}
/*
s.substr(pos, n)
返回一个string，包含s中从pos开始的n个字符的拷贝（pos的默认值是0，n的默认值是s.size() - pos，即不加参数会默认拷贝整个s）
*/
