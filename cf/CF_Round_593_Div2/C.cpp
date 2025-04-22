#include<iostream>

using namespace std;

int n,num=1;
int grap[303][303];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i%2==0)
            {
                grap[i][j]=num;
                num++;
            }
            else
            {
                grap[i][n-j+1]=num;
                num++;
            }
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<grap[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
