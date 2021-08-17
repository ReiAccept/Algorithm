#include<cstdio>
#include<algorithm>

using namespace std;

int leftn,rightn,mid;
int s,n,m,sg,cnt,num;
int ST[100000];

int main()
{
    scanf("%d%d%d",&s,&n,&m);
    leftn=1,rightn=s;
    for(int i=0; i<n; i++)
        scanf("%d",&ST[i]);
    sort(ST,ST+n);
    while(leftn!=rightn)
    {
        mid=(leftn+rightn+1)/2;
        sg=cnt=0;
        for(num=0; num<n; num++)
        {
            if(s-ST[num]<mid)
                break;
            if(ST[num]-sg<mid)
                cnt++;
            else
                sg=ST[num];
        }
        cnt+=n-num;
        if(cnt<=m)
            leftn=mid;
        else
            rightn=mid-1;
    }
    printf("%d",leftn);
    return 0;
}
