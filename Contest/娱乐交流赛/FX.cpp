#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    string s1, s2;
    while( cin >> s1 >> s2 )
    {
        bool flag = false;
        ll num = 0;
        for( ll i = 0; i < s1.length(); i ++ )
        {
            if( s1[i] == s2[i] && s1[i] == '0' )
            {
                flag = true;
            }
            if( flag )
            {
                if( i > 0 )
                {
                    if( s1[i-1] == '0' || s2[i-1] == '0' )
                    {
                        s1[i] = 'x', s2[i] = 'x';
                        num ++, flag = false;
                    }
                }
                if( i < s1.length() - 1 )
                {
                    if( s1[i+1] == '0' && flag )
                    {
                        s1[i] = 'x', s2[i] = 'x', s1[i+1] = 'x';
                        num ++, flag = false;
                    }
                    if( s2[i+1] == '0' && flag )
                    {
                        s1[i] = 'x', s2[i] = 'x', s2[i+1] = 'x';
                        num ++;
                    }
                }
                flag = false;
            }
        }
        cout << num << endl;
    }
    return 0;
}
