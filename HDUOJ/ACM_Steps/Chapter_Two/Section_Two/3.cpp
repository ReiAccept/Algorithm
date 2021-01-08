#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define int long long
//#define int __int128
#define ull unsigned long long
#define mmst0(x) memset(x,0,sizeof(x))

using namespace std;
//using namespace __gnu_pbds;

const int INF=0x3f3f3f3f;

int read(){char c;int num,f=1;while(c=(char)getchar(),!isdigit(c))if(c=='-')f=-1;num=(int)(c-'0');while(c=(char)getchar(),isdigit(c))num=num*10+(int)(c-'0');return num*f;}
void prt(int x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}

// bool hanoi(int n,int start[],int end[],int zhongjian[]){
// 	if(zhongjian[0] == n) return 0;
// 	else if(start[0] == n) return hanoi(n-1,start+1,zhongjian,end);
// 	else if(end[0] == n) return hanoi(n-1,zhongjian,end+1,start);
// 	return 1; 
// }

// bool hanoi2(int n,int start[],int zhongjian[],int end[]){
// 	if(zhongjian[0] == n) return 0;
// 	else if(start[0] == n) return hanoi2(n-1,start+1,zhongjian,end);
// 	else if(end[0] == n) return hanoi2(n-1,zhongjian,end+1,start);
// 	return 1; 
// }

bool hannuo(int n,int a[],int b[],int c[])
{
    if(b[0]==n) return false;
    else if(a[0]==n) return hannuo(n-1,a+1,c,b);
    else if(c[0]==n) return hannuo(n-1,b,a,c+1);//c[1]==n->n已经被移动到了C柱上,意味着要将C-1个盘子移动到C上,此时A和C柱子不能移动,B柱子上是堆好的n-1个盘子
    return true;
}

void work()
{
    int n=read();
    int a[70],b[70],c[70];
    int m=read();for(int i=1;i<=m;i++)a[i]=read();
    int p=read();for(int i=1;i<=p;i++)b[i]=read();
    int q=read();for(int i=1;i<=q;i++)c[i]=read();
    a[0]=b[0]=c[0]=a[m+1]=b[p+1]=c[q+1]=-INF;

    // if(hanoi(n,a+1,c+1,b+1))cout<<"true"<<endl;
    // else cout<<"false"<<endl;

    // if(hanoi2(n,a+1,b+1,c+1))cout<<"true"<<endl;
    // else cout<<"false"<<endl;

    if(hannuo(n,a+1,b+1,c+1))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return;
}

signed main()
{
    //ios::sync_with_stdio(false);cin.tie(NULL);
    int T=read();
    for(int Case=1;Case<=T;Case++)
    {
        //printf("Case #%d: ",Case);
        work();
    }
    return 0;
}
