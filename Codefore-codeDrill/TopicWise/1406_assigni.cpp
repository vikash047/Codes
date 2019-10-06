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

const int N = 17;
vector<int> g[N];
bool visit[N][1 << N], appers[1 << N];
int dp[1 << N];

void dfs(int u, int mask) {
    visit[u][mask] = true;
    appers[mask] = true;
    for(auto it : g[u]) {
        if(!visit[it][mask | (1 << it)]) {
            dfs(it, mask | (1 << it));
        }
    }
}

const int64 inf = 1e9;
int findDisjointPath(int pathMask) {
    if(pathMask == 0) return 0;
    int &r = dp[pathMask];
    if(r != -1) return r;
    r = inf;
    for(int i = pathMask; i > 0; i = pathMask &(i-1)) {
        if(appers[i]) {
            r = min(r, 1 + findDisjointPath(pathMask ^ i));
        }
    }
    return r;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        for(int i = 0; i < N; i++) {
            g[i].clear();
        }
        memset(visit, false, sizeof(visit));
        memset(appers, false, sizeof(appers));
        memset(dp, -1, sizeof(dp));
        int n, m;
        scanf("%d%d", &n, &m);
        int u, v;
        for(int i = 1; i <= m; i++) {
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
        }
        for(int i = 0; i < n; i++) {
            if(!visit[i][1 << i]) {
                dfs(i, 1 << i);
            }
        }
        int ans = findDisjointPath((1 << n) - 1);
        printf("Case %d: %d\n", test, ans);
    }
    return 0;
}
