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

const int MAXN = 100011;
const int MOD = 10007;
vector<int> g[MAXN];
int ways[MAXN][2];
int dp[MAXN][2];
int n;

void solve(int u, int par) {
    dp[u][1] = 1;
    dp[u][0] = 0;
    fri(i, g[u].size()) {
        int v = g[u][i];
        if(v == par) continue;
        solve(v, u);
        dp[u][1] += min(dp[v][0], dp[v][1]);
        dp[u][0] += dp[v][1];
        if(dp[v][1] == dp[v][0]) {
            ways[u][1] *= (ways[v][1]+ways[v][0]);
            ways[u][0] *= ways[v][1];
        } else {
            ways[u][1] *= (min(dp[v][1], dp[v][0]) == dp[v][1] ? ways[v][1] : ways[v][0]);
            ways[u][0] *= ways[v][1];
        }
        ways[u][1] %= MOD;
        ways[u][0] %= MOD;
    }
}

void clear(int n) {
    frei(i, 0, n) {
        ways[i][0] = ways[i][1] = 1;
        dp[i][0] = n+1, dp[i][1] = n+1;
        g[i].clear(); 
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        clear(n);
        int x, y;
        fri(i, n-1) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        solve(1, 0);
        if(dp[1][1] == dp[1][0]) {
            cout << dp[1][1] << " " << (ways[1][1] + ways[1][0])%MOD << endl;
        } else if(dp[1][1] < dp[1][0]) {
            cout << dp[1][1] << " " << ways[1][1] << endl;
        } else {
            cout << dp[1][0] << " " << ways[1][0] << endl;
        }
    }
    return 0;
}