#include<bits/stdc++.h>

using namespace std;

int l,T;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>l>>str;
        int i=0,j=1;
        str=str+str;
        while(j<l)
        {
            int k=0;
            while(k<l && str[j+k]==str[i+k]) k++;
            if(k==l) break;
            if(str[j+k]<str[i+k]) i=max(j+1,i+k+1);
            else j=j+k+1;
            if(i>j) swap(i,j);
        }
        cout<<i<<endl;
    }
    return 0;
}
