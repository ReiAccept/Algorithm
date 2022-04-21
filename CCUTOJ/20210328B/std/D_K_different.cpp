#include <stdio.h>

int main(void) {
    int arr[1005];
    int n, q, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if (arr[i] < arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d", &x);
        printf("%d\n", arr[x]);
    }
    return 0;
}