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

int n;
int m;
const int inf = 1 << 28;
const int maxn = 16;
int degree[16];
int g[maxn][maxn];
int64 dp[1 << maxn];

void floyd_warshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
}


int64 function(int mask) {
    if(mask == 0) return 0;
    int64 &ret = dp[mask];
    if(ret != -1) return ret;
    int pos = 0;
    for(int i = 0; i < n; i++) {
        if((mask & (1 << i))) {
            pos = i;
            break;
        }
    }
    ret = inf;
    for(int i = pos + 1; i < n; i++) {
        if((mask & (1 << i))) {
            int tmask = mask;
            tmask = tmask & ~(1 << pos);
            tmask = tmask & ~(1 << i);
            ret = min(ret, g[pos][i] + function(tmask));
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cin >> n >> m;
        for(int i = 0; i < maxn; i++) {
            for(int j = 0; j < maxn; j++) {
                g[i][j] = inf;
            }
            degree[i] = 0;
        }
        int x, y , c;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            cin >> x >> y >> c;
            x--;
            y--;
            g[x][y] = min(g[x][y], c);
            g[y][x] = min(g[y][x], c);
            degree[x]++;
            degree[y]++;
            ans += c;
        }
        floyd_warshall();
        int mask = 0;
        for(int i = 0; i < n; i++) {
            if(degree[i]%2) {
                mask = mask | (1 << i);
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << "Case " << cs << ": " << ans + function(mask) << endl;
    }
    
    return 0;
}
