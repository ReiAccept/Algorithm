/**
 * @author  Moe_Sakiya      i@tun.moe
 * @date        2018-07-28 13:34:34
 *
 */
 
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
unsigned long long int dparr[100005][2];
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int Q, k, l, r;
    unsigned long long int ans;
    scanf("%d %d", &Q, &k);
    dparr[0][0] = 1;
    for(int i = 1; i <= 100005; i++) {
        dparr[i][0] = (dparr[i - 1][0] + dparr[i - 1][1]) % 1000000007;
        if (i >= k)
            dparr[i][1] = dparr[i - k][0];
    }
    for(int i = 1; i <= 100005; i++) {
        dparr[i][0] = (dparr[i][0] + dparr[i][1]) % 1000000007;
        dparr[i][0] += dparr[i - 1][0];
    }
    for(int i = 0; i < Q; i++) {
        scanf("%d %d", &l, &r);
        ans = (dparr[r][0] - dparr[l - 1][0]) % 1000000007;
        printf("%llu\n", ans );
    }
    return 0;
}