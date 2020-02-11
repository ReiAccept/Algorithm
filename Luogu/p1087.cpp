#include<cstdio>
#include<iostream>

using namespace std;

int n;
string str;

char FBI(string s)
{
    if(s.size()>1)
    {
        cout<<FBI(s.substr(0,s.size()>>1));
        cout<<FBI(s.substr(s.size()>>1));
    }
    if(s==string(s.size(),'0')) return 'B';
    if(s==string(s.size(),'1')) return 'I';
    return 'F';
}

int main()
{
    cin>>n>>str;
    cout<<FBI(str)<<endl;
    return 0;
}
/*
void BinTree::Print(Node *p)//后序遍历
{
    if(p==NULL)
        return;
    Print(p->lchild);//访问左子树
    Print(p->rchild);//访问右子树
    cout<<p->data<<" ";//遍历
}
*/
