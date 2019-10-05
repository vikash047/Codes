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

const int N = 1e5+5;
const int LG = 19;

vector<pii> g[N];
int visit[N], tin[N], tout[N],minAcc[N], bridges[N], parent[LG][N], level[N];
vector<int> tree[N];
vector<int> vertices[N];
int storeComp[N];
queue<int> pq[N];
int grp = 1, n, m, T = 0;

void dfs(int u, int par) {
    visit[u] = 1;
    tin[u] = ++T;
    minAcc[u] = tin[u];
    for(auto it : g[u]) {
        if(it.ff == par) {
            continue;
        }
        if(visit[it.ff]) {
            minAcc[u] = min(minAcc[u], tin[it.ff]);
            continue;
        }
        dfs(it.ff, u);
        minAcc[u] = min(minAcc[u], minAcc[it.ff]);
        if(minAcc[it.ff] > tin[u]) {
            bridges[it.ss] = 1;
        }
    } 
}

int visit2[N];
void dfs2(int u) {
    int comp = grp;
    pq[comp].push(u);
    visit2[u] = 1;
    while(!pq[comp].empty()) {
        int node = pq[comp].front();
        pq[comp].pop();
        vertices[comp].push_back(node);
        storeComp[node] = comp;
        for(auto it : g[node]) {
            if(visit2[it.ff]) continue;
            if(bridges[it.ss]) {
                ++grp;
                tree[comp].push_back(grp);
                tree[grp].push_back(comp);
                dfs2(it.ff);
            } else {
                pq[comp].push(it.ff);
                visit2[it.ff] = 1;
            }
        }
    }
}

void dfs3(int u, int par, int lvl) {
    parent[0][u] = par;
    level[u] = lvl;
    for(auto it : tree[u]) {
        if(it == par) continue;
        dfs3(it, u, lvl + 1);
    }
}

void precompute(){
    for(int i = 1; i < LG; i++) {
        for(int j = 1; j <= n; j++) {
            if(parent[i-1][j]) {
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }
    }
}

int LCA(int u, int v) {
    if(level[u] < level[v]) {
        swap(u, v);
    }
    int diff = level[u] - level[v];
    for(int i = LG-1; i >= 0; i--) {
        if((1 << i) & diff) {
            u = parent[i][u];
        }
    }
    if(u == v) return v;
    for(int i = LG - 1; i >= 0; i--) {
        if(parent[i][u] && parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int dist(int u, int v) {
    return level[u] + level[v] - 2*level[LCA(u, v)];
}
int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(mp(v, i));
        g[v].push_back(mp(u, i));
    }
    dfs(1, 0);
    dfs2(1);
    dfs3(1, 1, 1);
    precompute();
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> u >> v;
        cout << dist(storeComp[u], storeComp[v]) << endl;
    }
    return 0;
}
