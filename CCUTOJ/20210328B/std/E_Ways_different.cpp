#include <stdio.h>
#include <string.h>

int n, m, d, w;
char G[35][35];
char route[35];

int main(void) {
    scanf("%d %d %d %d", &n, &m, &d, &w);
    for(int i = 0; i < n; i++)
        scanf("%s", G[i]);
    int x, y, h, dmg, len;
    for(int i = 0; i < d; i++) {
        dmg = 0;
        scanf("%d %d %d %s", &h, &x, &y, route);
        if (G[x][y] == 'P')
            dmg += w;
        len = strlen(route);
        for(int j = 0; j < len; j++) {
            switch (route[j]) {
                case 'W':
                    x--;
                    break;
                case 'S':
                    x++;
                    break;
                case 'A':
                    y--;
                    break;
                case 'D':
                    y++;
                    break;
            }
            if (G[x][y] == 'P')
                dmg += w;
        }
        if (dmg >= h)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}