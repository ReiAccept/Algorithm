#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char g_a[100];
int g_n,g_b[100]= {0},g_c[100]= {0},g_len;

void inPut()
{
    scanf("%d",&g_n);
    scanf("%s",g_a);
    g_len=strlen(g_a);
}

void change(char a[],int b[])
{
    int i;
    int len=strlen(a);
    for(i=0; i<len; i++)
    {
        if(g_n>10 && a[i]>='A')
            b[i]=a[i]-'A'+10;
        else
            b[i]=a[i]-'0';
    }
}

void invertedSequence(int temp1[],int temp2[])
{
    int i;
    for(i=0; i<g_len; i++)
        temp2[i]=temp1[g_len-1-i];
}

void add()
{
    int i;
    g_b[g_len]=0;
    for(i=0; i<g_len; i++)
    {
        g_b[i]+=g_c[i];
        if(g_b[i]>g_n-1)
        {
            g_b[i+1]+=g_b[i]/g_n;
            g_b[i]=g_b[i]%g_n;
        }
    }
    if(g_b[g_len])
        g_len++;
}

void outPut(int flag)
{
    if(flag)
        printf("STEP=%d",flag);
    else
        printf("Impossible!");
    printf("\n");
}

int check()
{
    int i;
    for(i=0; i<=g_len/2; i++)
    {
        if(g_b[i]!=g_b[g_len-1-i])
            return 0;
    }
    return 1;
}

int main()
{
    inPut();
    change(g_a,g_b);
    int flag=0;
    while(1)
    {
        if(flag>30)
        {
            flag=0;
            break;
        }
        if(flag!=0 && check())
            break;
        invertedSequence(g_b,g_c);
        add();
        flag++;
    }
    outPut(flag);
    return 0;
}
