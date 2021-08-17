#include <bits/stdc++.h>
#define maxn 100

using namespace std;

int b,n,m,sum;
int a[maxn];
string s;

int main()
{
    
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "He/She is from ";
            cin >> s;
            string substr = s.substr(0, 2);
            int sub = (substr[0] - '0') * 10 + substr[1] - '0';
            switch (sub)
            {
            case 33:
                cout << "Zhejiang";
                break;
            case 11:
                cout << "Beijing";
                break;
            case 71:
                cout << "Taiwan";
                break;
            case 81:
                cout << "Hong Kong";
                break;
            case 82:
                cout << "Macao";
                break;
            case 54:
                cout << "Tibet";
                break;
            case 21:
                cout << "Liaoning";
                break;
            case 31:
                cout << "Shanghai";
                break;
            }
            cout << ",and his/her birthday is on ";
            substr = s.substr(6, 4);
            string substrmonth = s.substr(10, 2);
            string substrday = s.substr(12, 2);
            cout << substrmonth << "," << substrday << "," << substr;
            cout << " based on the table." << endl;
        }
    }
    return 0;
}