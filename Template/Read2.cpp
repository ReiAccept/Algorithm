int read(){
	int a=0,b=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')b=-1;c=getchar();}
	while(c>='0'&&c<='9')a=a*10+c-48,c=getchar();
	return a*b;
}
