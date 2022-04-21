#include <stdio.h>

int n;
int arr[105], cnt[2], loc[2];

int main(void) {
    while (~scanf("%d", &n)) {
        cnt[0] = cnt[1] = 0;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < n; i++) {
            cnt[arr[i] % 2]++;
            loc[arr[i] % 2] = arr[i];
        }
        if (cnt[0] == 1)
            printf("%d\n", loc[0]);
        else
            printf("%d\n", loc[1]);
    }
    return 0;
}