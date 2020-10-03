bool isprime(int a)
{
    if(a==2||a==3)return true;
    if(a==1 || (a%6!=1&&a%6!=5))return false;
    for(int i=5; i<=(int)sqrt(a)+1; i+=6)if(a%i==0||a%(i+2)==0)return false;
    return true;
}
