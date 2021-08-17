/*
ID:sa128471
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

struct M
{
    int begt,endt;
};

vector <M> t1;
set <int> result;

int main()
{
    freopen("milk2.in","r",stdin);
    //freopen("milk2.out","w",stdout);
    int n,workN=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        M tmp;
        cin>>tmp.begt>>tmp.endt;
        result.insert(tmp.endt-tmp.begt);
        t1.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
        if(t1[i].endt>=t1[i+1].begt)
            if(workN==0)
                workN=t1[i+1].endt-t1[i].begt;
            else
                workN+=t1[i+1].endt-t1[i].endt;
        else
        {
            result.insert(workN);
            workN=0;
            break;
        }
    }
    cout<<*--result.end()<<" ";
    result.clear();
    result.insert(0);
    for(int i=0;i<n-1;i++)
    {
        if(t1[i].endt<t1[i+1].begt)
            result.insert(t1[i+1].begt-t1[i].endt);
    }
    cout<<*--result.end()<<endl;
    return 0;
}

/*
#include<stdio.h>

int N;
int WorkTime[1000001]={0};
int Work1,Work2;
int i,j;
int maxWork,max,maxFree=0;
int min=1000001;
int ans1,ans2;

int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    scanf("%d",&N);
    max=0;min=1000001;
    for(i=1;i<=N;i++) {
        scanf("%d %d",&Work1,&Work2);
        for(j=Work1+1;j<=Work2;j++){
        WorkTime[j]=1;
        if(Work1<min)min=Work1;
        if(Work2>max)max=Work2;
        }
    }
    for(i=min;i<=max+1;i++){
       if(WorkTime[i]==1){
                ans1++;
       }else{
        if(ans1>maxWork) maxWork=ans1;
        ans1=0;
    }
}
    for(i=min+1;i<=max;i++){
       if(WorkTime[i]==0) ans2++;
       else{
            if(ans2>maxFree) maxFree=ans2;
            ans2=0;
       }
    }
    printf("%d %d\n",maxWork,maxFree);
}
*/
