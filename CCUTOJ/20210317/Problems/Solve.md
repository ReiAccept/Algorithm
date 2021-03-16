```cpp
string a;
string b="think different";

void work()
{
    while(getline(cin,a))
    {
        int ans=0;
        for(int i=0;i<a.size();i++)
            if(a[i]=='t' || a[i]=='T')
            {
                bool flag=true;
                for(int j=0;j<b.size();j++)
                {
                    if(a[i+j]!=b[j] && a[i+j]!=(b[j]-'a'+'A'))
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        cout<<ans<<endl;
    }
    return;
}
```

```cpp
void work(int a,int n=1)
{
    if(a<=10)
    {
        cout<<"1"<<endl;
        return;
    }
    while(a>=10)
    {
        a+=5;
        a/=10;
        n*=10;
    }
    cout<<a*n<<endl;
    return;
}
```

```cpp
int n, a[1010], cnt;

void work()
{
    while (scanf("%d", &n) && n) 
    {
        cnt = 0;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int j = 1; j < n; j++) 
        {
            for (int i = 0; i < n - j; i++) 
            {
                if (a[i] > a[i + 1]) {
                    swap(a[i],a[i+1]);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return;
}
```

```java
import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int Case;
        Case = sc.nextInt();
        while(Case > 0) {
            Case--;
            BigInteger a =  new BigInteger("0");	
            BigInteger b = sc.nextBigInteger();
            BigInteger zero = new BigInteger("0");
            while(b.intValue() != 0) {
                a = a.add(b);
                b = sc.nextBigInteger();
            }
            System.out.println(a);
            System.out.println("");
        }
        
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

```cpp
int read(){int s=0,w=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
           while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();} return s*w;}
```

