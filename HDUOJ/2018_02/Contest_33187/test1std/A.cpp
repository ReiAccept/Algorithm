#include<cstdio>
int T,i,j,sum;
char a[20][20];
bool v[20][20];
bool can(int x,int y){
  if(x<0||y<0||x>11||y>11)return 0;
  return !v[x][y]&&a[x][y]!='#';
}
void dfs(int x,int y){
  v[x][y]=1;
  if(can(x-1,y))dfs(x-1,y);
  if(can(x+1,y))dfs(x+1,y);
  if(can(x,y-1))dfs(x,y-1);
  if(can(x,y+1))dfs(x,y+1);
}
int work(){
  for(i=1;i<=10;i++)scanf("%s",a[i]+1);
  for(i=0;i<=11;i++)for(j=0;j<=11;j++)v[i][j]=0;
  sum=0;
  for(i=0;i<=11;i++)for(j=0;j<=11;j++)if(!v[i][j]&&a[i][j]!='#')dfs(i,j),sum++;
  if(sum==1)return 1;
  if(sum==2)return 0;
  return 8;
}
int main(){
  scanf("%d",&T);
  while(T--)printf("%d\n",work());
  return 0;
}