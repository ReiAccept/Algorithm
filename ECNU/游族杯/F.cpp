#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Node
{
    string name="";
    bool leaf=true;
    vector<Node> s;
    void build(string str)
    {
        bool flag=false;
        unsigned int p=str.find('/');
        if(p!=str.npos)
        {
            string op=str.substr(0,p);
            for(unsigned int i=0; i<s.size(); i++)
            {
                if(s[i].name==op)
                {
                    s[i].build(str.substr(p+1));
                    flag=true;
                    leaf=false;
                    break;
                }
            }
            if(!flag)
            {
                Node empty;
                empty.name=op;
                s.push_back(empty);
            }
        }
        else
        {
            string op=str;
            for(unsigned int i=0; i<s.size(); i++)
            {
                if(s[i].name==op)
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                Node empty;
                empty.name=op;
                s.push_back(empty);
            }
        }
    }

} root;
int n,sum;

void findx(Node node)
{
    if(node.leaf)
    {
        for(unsigned int i=0;i<node.s.size();i++)
        {
            if(node.s[i].name.find(".eoj")!=node.s[i].name.npos)sum++;
            //cout<<node.s[i].name<<endl;
        }
    }
    else
    {
        for(unsigned int i=0;i<node.s.size();i++)
            findx(node.s[i]);
    }
}

int main()
{
    cin>>n;
    root.name="root";
    for(int I=1; I<=n; I++)
    {
        string str;
        cin>>str;
        root.build(str.substr(1));
    }
    //cout<<"now findx"<<endl;
    findx(root);
    cout<<sum<<endl;
    return 0;
}
