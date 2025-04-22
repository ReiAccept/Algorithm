#include <cstdio>
#include<stack>

using namespace std;

int n,a[1005];
int flag,start;//flag���λ,start��ʼλ
bool result=true;

stack<int> s;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(flag<n)
    {
        if(start==a[flag])
        {
            start++;
            flag++;
        }
        else if(!s.empty() && s.top()==a[flag] )
        {
            s.pop();
            flag++;
        }
        else if(start<=n)
        {
            s.push(start++);
        }
        else
        {
            result=false;
            break;
        }
    }

    if(result)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}


/*
#include<iostream>//д��C++����
#include<stack>//���ö�ջ
using namespace std;//ʹ�ñ�׼�����ռ�
int main()
{
    int n,target[100];//��������
    cin>>n;
    for(int i=1; i<=n; i++) //�Ӽ�������𳵳�վ������
    {
        cin>>target[i];//���뵽��վĿ�������У�Ҳ����1...n���ܵĳ�վ˳��
    }
    int A=1,B=1;//A����ʼ1....n����վ����ʼλ�ã�B������
    stack<int> s;//����һ����ջ
    int ok=1;//��־λ���Ƿ���ܳ������ֳ�վ˳��
    while(B<=n)//��־λû�г������ֵ
    {
        if(A==target[B]) //�����һ��Ŀ����ǻ���ڵ�һ���Ļ�����ô�����ǽ�վ���̳�վ�����ֿ�������Ҫ
        {
            A++;
            B++;//����A����һ��׼��������B��һ��Ŀ�����㣬�ڶ���Ŀ��׼��
        }
        else if(!s.empty()&&s.top()==target[B] )  //���վ��Ϊ�գ�����վ������Ŀ������Ŀ�����ӣ��������վ��Ļ𳵳�վ
        {
            s.pop();
            B++;
        }
        else if(A<=n)
        {
            s.push(A++);//�����ʼҪС��nҲ������ʼλ�û��л��ţ���ô����һ�κ����Ҫ��һ���𳵽�վ
        }
        else   //�����ʼվ��û�л��ˣ�B��û�յ����л𳵣���ʱ�������д������˳��
        {
            ok=0;
            break;
        }
    }
    if(ok) //��ʼ������������B�յ����л𳵣���ʱ�𳵿��������ַ�ʽ��վ�����򲻿��ܣ�һ���ǿ��ܵ���������ͼ
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
*/
