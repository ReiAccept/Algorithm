#include<iostream>
#include<algorithm>

using namespace std;

int c,out;
int word[10];

int getst(string s)
{
    if(s=="one"||s=="a"||s=="first"||s=="another"){word[c]=1;c++;return 0;}
     if(s=="two"||s=="both"||s=="second"){word[c]=4;c++;return 0;}
     if(s=="three"||s=="third"){word[c]=9;c++;return 0;}
     if(s=="four"){word[c]=16;c++;return 0;}
     if(s=="five"){word[c]=25;c++;return 0;}
     if(s=="six"){word[c]=36;c++;return 0;}
     if(s=="seven"){word[c]=49;c++;return 0;}
     if(s=="eight"){word[c]=64;c++;return 0;}
     if(s=="nine"){word[c]=81;c++;return 0;}
     if(s=="eleven"){word[c]=21;c++;return 0;}
     if(s=="twelve"){word[c]=44;c++;return 0;}
     if(s=="thirteen"){word[c]=69;c++;return 0;}
     if(s=="fourteen"){word[c]=96;c++;return 0;}
     if(s=="fifteen"){word[c]=25;c++;return 0;}
     if(s=="sixteen"){word[c]=56;c++;return 0;}
     if(s=="seventeen"){word[c]=89;c++;return 0;}
     if(s=="eightteen"){word[c]=24;c++;return 0;}
     if(s=="nineteen"){word[c]=61;c++;return 0;}
}

int main()
{
    for(int i=1;i<=6;i++)
    {
        string str;
        cin>>str;
        if(str[str.size()-1]=='.') str.erase(str.size()-1,1);
        getst(str);
    }
    sort(word,word+c);
    for(int i=0;i<c;i++)
    {
        out+=word[i];
        out*=100;
    }
    cout<<out/100<<endl;
    return 0;
}
