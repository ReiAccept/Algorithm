#include<cmath>
#include<cstdio>
#include<climits>

using namespace std;

int T,n,m;//m��n����֮��,��ȡ���������5
int a[20003],s[20003],f[20003][210];

inline void up(int &a,int b){a<b?(a=b):0;}
//�ҿ�QTMD��Ŀ�����,ÿ�ζ�������д��ע��
//������ָ���a<b�Ļ�,��ô��a=b����Ļ�,ʲô������
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		m=(int(sqrt(n*2))+5);
		for(int i=1;i<=m;i++)
			s[i]=s[i-1]+a[i];
		for(int i=1;i<=m;i++)
			f[n+1][i]=0;
		for(int i=n;i;i--)
		{

		}
	}
	return 0;
}
