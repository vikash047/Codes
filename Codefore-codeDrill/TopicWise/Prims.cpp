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

const int N = 2*1e5 + 5;

vector<pii> g[N], tree[N];
int visit[N], parent[N], u[N], v[N], w[N];
int64 dist[N];
int n, m;
const int inf = 1e10;
class Comp{
    public:
    bool operator()(const pii a, const pii b) {
        return a.ff > b.ff;
    }
};

int primMST(int source) {
    priority_queue<pii, vector<pii>, Comp> pq;
    memset(visit, 0, sizeof(visit));
    for(int i = 1; i <= n; i++) dist[i] = inf;
    dist[source] = 0;
    pq.push(mp(0, source));
    int cost = 0;
    parent[source] = source;
    while(!pq.empty()) {
        pii node = pq.top();
        pq.pop();
        int vv = node.ss;
        int ww = node.ff;
        int pp = parent[vv];
        if(visit[vv]) continue;
        //cout << " incident " << vv << " from " << pp << " wt " << ww << endl;
        visit[vv] = 1;
        if(vv != pp) {
            tree[pp].push_back(mp(vv, ww));
            tree[vv].push_back(mp(pp, ww));
        }
        
        cost += ww;
        for(auto it : g[vv]) {
            //cout << it.ff << "  " << it.ss << endl;
            if(visit[it.ff]) {
                continue;
            }
            //cout << dist[it.ff] << endl;
            if(dist[it.ff] > it.ss) {
                dist[it.ff] = it.ss;
                parent[it.ff] = vv;
                pq.push(mp(dist[it.ff], it.ff));
            }
        }
    }
    return cost;
}

const int LG = 20;
int par[LG][N], maxwt[LG][N], level[N];
void dfs(int s, int pp, int ewt, int lvl) {
    par[0][s] = pp;
    maxwt[0][s] = ewt;
    level[s] = lvl;
    for(auto it : tree[s]) {
        if(it.ff == pp) continue;
        dfs(it.ff, s, it.ss, lvl + 1);
    }
}

void precompute() {
    for(int i = 1; i < LG; i++) {
        for(int j = 1; j <= n; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
            maxwt[i][j] = max(maxwt[i-1][j], maxwt[i-1][par[i-1][j]]);
        }
    }
}

int LCA(int x, int y) {
    if(level[x] < level[y]) {
        swap(x, y);
    }
    int diff = level[x] - level[y];
    int ans = 0;
    for(int i = LG - 1; i >= 0; i--) {
        if((1 << i) & diff) {
            ans = max(ans, maxwt[i][x]);
            x = par[i][x];
        }
    }
    if(x == y) {
        return ans;
    }
    for(int i = LG - 1; i >= 0; i--) {
        if(par[i][x] && par[i][y] && par[i][x] != par[i][y]) {
            ans = max(ans, maxwt[i][x]);
            ans = max(ans, maxwt[i][y]);
            x = par[i][x];
            y = par[i][y];
        }
    }
    ans = max(ans, par[0][x]);
    ans = max(ans, par[0][y]);
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back(mp(v[i], w[i]));
        g[v[i]].push_back(mp(u[i], w[i]));
    }
    int ans = primMST(1);
    //cout << ans << endl;
    dfs(1, 1, 0, 1);
    precompute();
    for(int i = 1; i <= m; i++) {
        int x = u[i];
        int y = v[i];
        int wt = w[i];
        int maxwte = LCA(x, y);
        cout << ans - maxwte + w[i] << endl;
    }
    return 0;
}
