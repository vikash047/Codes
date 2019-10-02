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

const int N = 500;
struct Edge {
    int u, int v, int w, int idx;
    Edge(int _u, int _v, int _w, int _idx) :
        u(_u), v(_v), w(_w), idx(_idx) {}
} edges[N];

int n, m; connected;
int root[N], sz[N];
vector<pii> g[N];

void init() {
    for(int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;
    }
    connected = n;
}

int getRoot(int u) {
    if(root[u] == u) {
        return u;
    }
    root[u] = getRoot(root[u]);
    return root[u];
}

void merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if(u == v) return;
    connected--;
    if(sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    sz[u] = 0;
    root[u] = root[v];
}

bool Comp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

void addEdge(int u, int v, int w, int idx) {
    g[u].push_back(mp(v, w));
    g[v].push_back(mp(u, w));
    edges[idx] = Edge(u, v, w, idx);
}

int KruskalMst() {
    init();
    int cost = 0;
    sort(edges + 1, edges + m + 1);
    for(int i = 1; i <= m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int rt1 = getRoot(u);
        int rt2 = getRoot(v);
        if(rt1 == rt2) continue;
        cost += w;
        merge(u, v);
    }
    return cost;
}

int main(int argc, char const *argv[])
{
    /* code */

    return 0;
}
