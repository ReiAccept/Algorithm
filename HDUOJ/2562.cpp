#include <iostream>
#include <cstring>

using namespace std;

int t;
char num[51];

int main()
{
    cin>>t;
    while (t--)
    {
        cin >> num;
        int len=(int)strlen(num);
        for(int i=0; i<len-1; i+=2) swap(num[i], num[i+1]);
        cout << num << endl;
    }
    return 0;
}
