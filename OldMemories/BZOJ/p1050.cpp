class BCJ
{
	private:
		vector<int> fa;
	public:
		BCJ(int n)
		{
			for(int i=0;i<=n;i++)
				fa.push_back(i);
		}
		int find(int x)
		{
			if(x!=fa[x])
				fa[x]=find(fa[x]);
			return fa[x];
		}
		void mix(int x,int y)
		{
			fa[find(x)]=find(y);
		}
};

