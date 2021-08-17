#include <iostream>

using namespace std;

int t,f[21]= {1,3};

int main ()
{

    for (int i=2; i<21; i++) f[i] = f[i - 1] * 2 + f[i - 2];
    cin >> t;
    while ( t-- )
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
