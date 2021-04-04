#include <stdio.h>

int main(void) {
    int n, m, num, res;
    scanf("%d %d", &n, &m);
    num = n / m;
    res = n % m;
    if (res == 0)
        for (int i = 0; i < m; i++)
            printf("%d%c", num, i != m - 1 ? ' ' : '\n');
    else {
        for (int i = 0; i < m; i++)
            printf("%d%c", i >= m - res ?num + 1 : num,
                   i != m - 1 ? ' ' : '\n');
    }
    return 0;
}