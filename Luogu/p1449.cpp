#include<stack>
#include<cstdio>
#include<iostream>

using namespace std;

int num;
stack<int> s;

int main()
{
    while(true)
    {
        char c=(char)getchar();
        if(c=='@') break;
        else if(c=='.')
        {
            s.push(num);
            num=0;
        }
        else if(c=='-')
        {
            int tmp=s.top();s.pop();
            tmp=s.top()-tmp;s.pop();
            s.push(tmp);
        }
        else if(c=='+')
        {
            int tmp=s.top();s.pop();
            tmp=tmp+s.top();s.pop();
            s.push(tmp);
        }
        else if(c=='*')
        {
            int tmp=s.top();s.pop();
            tmp=tmp*s.top();s.pop();
            s.push(tmp);
        }
        else if(c=='/')
        {
            int tmp=s.top();s.pop();
            tmp=s.top()/tmp;s.pop();
            s.push(tmp);
        }
        else num=(num*10)+(int)(c-'0');
    }
    cout<<s.top()<<endl;
    return 0;
}
