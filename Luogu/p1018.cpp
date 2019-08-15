#include<vector>
#include<iostream>

using namespace std;

struct B_Int
{
    vector <int> s;
    void read_str()
    {
        string str;
        cin>>str;
        for(int i=str.size()-1;i>=0;i--)
            s.push_back(str[i]-'a');
        //cout<<str;
    }
};

int n,k;
B_Int num;

int main()
{
    cin>>n>>k;
    num.read_str();
    return 0;
}
