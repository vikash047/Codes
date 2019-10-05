#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define pr pair

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 5005

int grid[21][21];
int dp[21][21][21][21];

int find(int x1, int x2, int y1, int y2) {
    int ret = 0;
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            if(grid[i][j]) ret++;
        }
    }
    return ret;
}

int solve(int x1, int x2, int y1, int y2) {
    int & ret = dp[x1][x2][y1][y2];
    if(ret != -1) return ret;
    int cnt = find(x1, x2, y1, y2);
    if(cnt == 1) return 0;
    if(cnt == 0) return INT_MAX/3;
    ret = INT_MAX;
    for(int i = x1; i <= x2; i++) {
        ret = min(ret, (solve(x1, i, y1, y2) + solve(i + 1, x2, y1, y2) + y2 - y1 + 1));
    }
    for(int i = y1; i <= y2; i++) {
        ret = min(ret, (solve(x1, x2, y1, i) + solve(x1, x2, i + 1, y2) + x2 - x1 + 1));
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, m-1, 0, n-1) << endl;

    return 0;
}
