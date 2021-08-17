#include <iostream>

using namespace std;

int t;
int num[10];

int main()
{
    cin >> t;
    while ( t-- )
    {
        int n;
        cin >> n;
        for ( int i = 0; i < n; i++ ) cin >> num[i];
        int tmp = 0;
        for ( int i = 1; i < n; i++ ) if ( num[tmp] > num[i] ) tmp = i;
        num[tmp] = 100;
        tmp = 0;
        for ( int i = 1; i < n; i++ ) if ( num[tmp] > num[i] ) tmp = i;
        cout << num[tmp] << endl;
    }
    return 0;
}
