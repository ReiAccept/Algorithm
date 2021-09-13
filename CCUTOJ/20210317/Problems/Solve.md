```cpp
string a,b="think different";
signed main()
{
    while(getline(cin,a))
    {
        int ans=0;
        for(int i=0;i<(int)a.size();i++)
            if(a[i]=='T' || a[i]=='t')
            {
                int flag=true;
                for(int j=0;j<(int)b.size() && flag;j++)
                {
                    if(a[i+j]==b[j] || a[i+j]==b[j]+'A'-'a') flag=true;
                    else flag=false;
                }
                if(flag) ans++;
            }
        cout<<ans<<endl;
    }
    return 0;
}
```

```cpp
int n,x;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x<=10)
        {
            cout<<1<<endl;
            continue;
        }
        int w=1;
        while(x>=10)
        {
            x+=5;
            x/=10;
            w*=10;
        }
        cout<<x*w<<endl;
    }
    return 0;
}
```

```cpp
int n;
int a[1003];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n && n)
    {
        int ans=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<n;i++)
            for(int j=0;j<n-i;j++)
                if(a[j]>a[j+1])
                {
                    swap(a[j],a[j+1]);
                    ans++;
                }
        cout<<ans<<endl;
    }
    return 0;
}
```

```java
int n;
string s;
int num[1003];
void add()
{
    int x=0;
    reverse(s.begin(),s.end());
    for(int i=0;i<(int)s.size();i++)
    {
        x+=s[i]-'0'+num[i];
        num[i]=(x%10);
        x/=10;
    }
    if(x)num[(int)s.size()]+=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--)
    {
        memset(num,0,sizeof(num));
        while(cin>>s && s!="0")add();
        int len=1000;
        while(!num[len])len--;
        while(len>=0)
        {
            cout<<num[len];
            len--;
        }
        cout<<endl;
    }
    
}
```

```cpp
int n,l,sx,sy;
char g[103][103];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='S')sx=i,sy=j;
        }
    cin>>l;
    for(int i=1;i<=l;i++)
    {
        char op;
        cin>>op;
        if(op=='W') if(sx!=1 && g[sx-1][sy]!='#')sx--;
        if(op=='S') if(sx!=n && g[sx+1][sy]!='#')sx++;
        if(op=='A') if(sy!=1 && g[sx][sy-1]!='#')sy--;
        if(op=='D') if(sy!=n && g[sx][sy+1]!='#')sy++;
        if(g[sx][sy]=='E')
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
```

```cpp
int n,s;
int r[10];
map<int,bool> m;

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        m.clear();
        for(int k=1;k<=n;k++)
        {
            cin>>s;
            for(int i=0;i<=9;i++)r[i]=0;
            for(int tmp,i=1;i<=s;i++)
            {
                cin>>tmp;
                r[tmp]++;
            }
            int sx=0;
            for(int j=9;j>=0;j--) if(r[j])sx=sx*10+j;
            m[sx]=true;
        }
        cout<<m.size()<<endl;
    }
    return 0;
}
```

