#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

char a[1003];
char k[103];

int main()
{
    cin>>k>>a;
    int nk=strlen(k);
    for(int i=0;i<nk;i++){
        if(k[i]>='A' && k[i]<='Z') k[i]+=32;
        k[i]-='a';
    }
    int n=strlen(a);
    //cout<<k<<endl<<a<<endl;
    for(int i=0;i<n;i++){
        if(a[i]>='a' && a[i]<='z'){
            a[i]-='a';
            a[i]=a[i]-(k[i%nk])+26;
            a[i]%=26;
            a[i]+='a';
        }
        if(a[i]>='A' && a[i]<='Z'){
            a[i]-='A';
            a[i]=a[i]-(k[i%nk])+26;
            a[i]%=26;
            a[i]+='A';
        }
    }
    cout<<a<<endl;
    return 0;
}
