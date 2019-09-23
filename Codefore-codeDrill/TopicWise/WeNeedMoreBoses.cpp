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

const int N = 3*1e5 + 2;
const int M = 3*1e5 + 2;
int n, m, maxDist, grp = 1, T = 0;
vector<pii> g[N];
vector<int> t[N];
int tin[N], tout[N], minAcc[N], bridges[M];
bool vis1[N], vis2[N];
queue<int> pq[N];

// connected bdriges in the graph
void dfs(int u, int par) {
    vis1[u] = true;
    tin[u] = ++T;
    minAcc[u] = tin[u];
    for(auto it : g[u]) {
        if(it.ff == par) continue;
        if(vis1[it.ff]) {
            minAcc[u] = min(minAcc[u], tin[it.ff]);
        } else {
            dfs(it.ff, u);
            minAcc[u] = min(minAcc[u], minAcc[it.ff]);
            if(minAcc[it.first] > tin[u]) {
                bridges[it.second] = 1;
                //cout << "Bridges "  << it.ss << endl;
            }
        }
    }
}

// you can merege or compress the graph using DSU
// only change in above dfs make a link between edge if they are not part of bridges.
// all bridges find out link component and make tree out of that.
vector<int> verticesCC[N];
// merge connected component using bfs and find the bridge then add to tree those merge componetes and find the next connected componets.
void bfs(int u) {
    int comp = grp;
    pq[comp].push(u);
    vis2[u] = 1;
    while(!pq[comp].empty()) {
        int node = pq[comp].front();
        pq[comp].pop();
        verticesCC[comp].push_back(node);
        //if(vis2[node]) continue;
        for(auto it : g[node]) {
            if(vis2[it.ff]) continue;
            if(bridges[it.ss]) {
                ++grp;                             
                //cout << "vertics in tree is " << comp << "  " << grp << endl;
                t[comp].push_back(grp);
                t[grp].push_back(comp);
                bfs(it.ff);
            } else {
                pq[comp].push(it.ff);
                vis2[it.ff] = 1;
            }
        }
    }
}

// find the diameter of the tree
// use bfs and dfs fist find the higest level node and then start from the that level and find the next highest lighest level that is diameter of the tree
int node = 1;
int dfsd(int u, int par, int lvl) {
    if(lvl > maxDist) {
        maxDist = lvl;
        node = u;
    }
    for(auto it : t[u]) {
        if(it == par) continue;
        dfsd(it, u, lvl + 1);
    }
}


int main(int argc, char const *argv[])
{
/* code */
    cin >> n >> m;
    int x, y;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(mp(y, i));
        g[y].push_back(mp(x, i));
    }
    dfs(1, 0);
    bfs(1);
    dfsd(1, 1, 0);
    dfsd(node, node, 0);
    cout << maxDist << endl;
    return 0;
}
