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

vector<int> g[100001];
int N;
int dp[100001][2];

void solve(int u, int par) {
    dp[u][1] = 1; 
    fri(i, g[u].size()) {
        int v = g[u][i];
        if(v == par) continue;
        solve(v, u);
        dp[u][1] += min(dp[v][1], dp[v][0]);
        dp[u][0] += (dp[v][1]);   
    }
}

int main() {
    cin >> N;
    int x, y;
    frei(i, 1, N-1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    solve(1, 0);
    int ans = min(dp[1][1], dp[1][0]);
    cout << ans << endl;
}