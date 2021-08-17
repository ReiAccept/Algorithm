#include <stdio.h>
#define MAX_BINARY_REC_LEN 32 + 5

int m, n, k;
long long res;
int binary_rec_len = 0; 
int binary_rec[MAX_BINARY_REC_LEN];
  
void init( void ) {
    scanf( "%d%d%d", &m, &n, &k );
    printf( "%d^%d mod %d=", m, n, k );
}

int main( void ) {
    //caculat m^n % k
    init();
    
    while( n!=0 )
    {
        binary_rec[binary_rec_len++] = n % 2;
        n /= 2;
    }
    
    int i;
    res = 1; //m^0 
    for( i=binary_rec_len-1; i>=0; i-- )
    {
        if( binary_rec[i] == 1 )
        {
            res = (res * res % k) * m % k;
        }else{
            res = res * res % k;
        }
    }
    
    printf( "%lld\n", res );
    return 0; 
}
