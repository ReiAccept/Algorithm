int pr[N],vis[N];

void PRIM(int lim,int cnt=0){//筛法板子
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            vis[i]=1;pr[++cnt]=i;
            for(int j=i;j<=lim/i;j++) vis[i*j]=1;
        }   
    }
}
