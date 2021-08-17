#include<bits/stdc++.h>

using namespace std;

int n,k;

vector<size_t> build(const std::string& s)
{
    vector<std::pair<std::string, size_t> > suffixes;
    for (size_t i = 0; i < s.length(); ++i) suffixes.emplace_back(s.substr(i), i);
    sort(suffixes.begin(), suffixes.end());
    vector<size_t> sa(s.length());
    for (size_t i = 0; i < s.length(); ++i)
    {
        sa[i] = suffixes[i].second;
        cout<<sa[i]<<" ";
    }
    return sa;
}



int main()
{
    //cin>>n>>k;
    build("cubercsl");
    return 0;
}

