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

const int N = 1e4 + 5;
int par[N], dsu_cc[N], dsu_2ecc[N], dsu_sz[N];
vector<int> lastVisit;
int lca_itr;
int bridges;

void init(int n) {
    lastVisit.resize(n+1);
    for(int i = 0; i <= n; i++) {
        par[i] = -1;
        dsu_cc[i] = dsu_2ecc[i] = i;
        dsu_sz[i] = 1;
        lastVisit[i] = 0;
    }
    lca_itr = 0;
    bridges = 0;
}

int getCC(int u) {
    if(u == -1) return -1;
    return dsu_cc[u] == u ? u : dsu_cc[u] = getCC(dsu_cc[u]);
}

int get2CC(int u) {
    if(u == -1) return -1;
    return dsu_2ecc[u] == u ? u : dsu_2ecc[u] = get2CC(dsu_2ecc[u]);
}

void makeRoot(int u) {
    u = get2CC(u);
    int root = u;
    int child = -1;
    while(u != -1) {
        int p = get2CC(par[u]);
        par[u] = child;
        dsu_cc[u] = root;
        child = u;
        u = p;
    }
    dsu_sz[root] = dsu_sz[child];
}

void mergePaths(int u, int v) {
    ++lca_itr;
    vector<int> path_u, path_v;
    int l = -1;

    while(l == -1) {
        if(u != -1) {
            u = get2CC(u);
            path_u.push_back(u);
            if(lastVisit[u] == lca_itr) 
                l = u;
            lastVisit[u] = lca_itr;
            u = par[u];
        }
        if(v != -1) {
            v = get2CC(v);
            path_v.push_back(v);
            if(lastVisit[v] == lca_itr) 
                l = v;
            lastVisit[v] = lca_itr;
            v = par[v];
        }
    }
    for(int u : path_u) {
        dsu_2ecc[u] = l;
        if(l == u) break;
        --bridges;
    }
    for(int v : path_v) {
        dsu_2ecc[v] = l;
        if(l == u) break;
        --bridges;
    }
}

void addEdge(int u, int v) {
    u = get2CC(u);
    v = get2CC(v);
    if(u == v) return;
    int cu = getCC(u);
    int cv = getCC(v);
    if(cu != cv) {
        // change the root
        ++bridges;
        if(dsu_sz[cu] > dsu_sz[cv]) {
            swap(u, v);
            swap(cu, cv);
        }
        makeRoot(u);
        par[u] = dsu_cc[u] = v;
        dsu_sz[cv] += dsu_sz[u];

    } else {
        // merge with lca
        mergePaths(u, v);
    }
}


int main(int argc, char const *argv[])
{
/* code */
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        init(n);
        int u, v;
        for(int i = 1; i <= m; i++) {
            cin >> u >> v;
            addEdge(u, v);
            cout << bridges << endl;
        }
    }

return 0;
}
