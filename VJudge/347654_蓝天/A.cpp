#include<iostream>

using namespace std;

int T;
string s;

int main()
{
    cin>>T;
    while(T--)
    {
        cin >> s;
        bool flag=true;
        for (unsigned int i=0;i<s.length();i++)
        {
            if(s[i]=='?')
            {
                int t=-1;
                for(int j=0;j<3;j++)
                    if ((i-1<0 || s[i-1]!=(char)('a'+j)) && (i+1>=s.length() || s[i+1]!=(char)('a'+j)))
                    {
                        t=j;
                        break;
                    }
                s[i]=(char)('a'+t);
            }
        }
        for (unsigned int i=1;i<s.length();i++) if(s[i]==s[i-1]) flag=false;
        cout<<(flag?s:"-1")<<endl;
    }
    return 0;
}
