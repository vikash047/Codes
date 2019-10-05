#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510;
int n, q, cas = 1;
int val[N][N];
int dp[N][N][10];

void init() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &val[i][j]);
            dp[i][j][0] = val[i][j];
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; (1 << j) <= n; j++)
            for (int k = 1; k + (1 << j) - 1 <= n; k++) {
                dp[i][k][j] = max(dp[i][k][j - 1], dp[i][k + (1 << (j - 1))][j - 1]) ;
            }
    }
}

int Query(int i, int x, int y) {
    int k = 0;
    while (x + (1 << (k + 1)) - 1 <= y) k++;
    return max(dp[i][x][k], dp[i][y - (1 << k) + 1][k]);
}

void solve() {
    int i, j, s;
    printf("Case %d:\n", cas++);
    while (q--) {
        scanf("%d%d%d", &i, &j, &s);
        int ans = 0;
        for (int k = i; k < i + s; k++) {
            ans = max(ans, Query(k, j, j + s - 1));
        }
        printf("%d\n", ans);
    }
}
int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        init();
        solve();
    }
    return 0;
}