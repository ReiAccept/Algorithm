/*
ID:sa128471
PROG: ride
LANG: C++
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;

int ma(char x);

int main()
{
	ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	int k1=1,k2=1;
    char c;
    string a,b;
    fin>>a>>b;
    //a.length();
    //b.length();
    for(int i=0;i<=5;i++)
    {
        if(a[i]=='\0')
            break;
        k1=k1*ma(a[i]);
        k1=k1%47;
    }

    for(int i=0;i<=5;i++)
    {
        if(b[i]=='\0')
            break;
        k2=k2*ma(b[i]);
        k2=k2%47;
    }
    //k1=k1%47;
    //k2=k2%47;
    if(k1==k2)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    return 0;
}

int ma(char in)
{
    return in-64;
}
