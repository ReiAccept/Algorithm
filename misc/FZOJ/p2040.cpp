#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,a,b,money,note;
int in[10001];
int vis[10001];
int pay[10001];
vector<int> graph[10001];
queue<int>q;

int main()
{
    cin>>n>>m;
    for(int i=0; i<10001; i++)
        pay[i]=100;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        graph[b].push_back(a);
        in[a]++;
    }
    while(true)
    {
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(in[i]==0 && vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
                flag=false;
            }
        }
        if(flag)
            break;
        while(!q.empty())
        {
            int mid=q.front();
            note++;
            q.pop();
            pay[mid]+=money;
            for(int x=0; x<graph[mid].size(); x++)
            {
                int next=graph[mid][x];
                in[next]--;
            }
        }
        money++;
    }
    if(note==n)
    {
        int sum=0;
        for(int h=1; h<=n; h++)
            sum+=pay[h];
        cout<<sum<<endl;
    }
    else
        cout<<"Poor Xed"<<endl;
    return 0;
}

/*
���ȹ�ͼ��������������a��Ǯ��b�ࡱ���b��һ������ָ��a��
 Ȼ�������������޷�����������ʾ�����޽⣨����Ȧ����
 �����Եõ��������������У�������˳����е��ƣ�
 ��f[i]��ʾ��i�������õ����ٽ�������
 ��������f[i]=100����Ŀ�и�������Сֵ����
 Ȼ��������˳�򿼲�ÿ����i�������������(j,i)�����ʾf[i]�����f[j]�����������f[i] = Max { f[i] , f[j]+1 }���ɣ�
 �������֮������f[i]��ֵҲ��ȷ���ˣ����𰸾͵���f[1]+��+f[n]
 */
