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

const int N = 205;
struct Node {
    int u, v, w;
    Node(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<int> g[N];
vector<Node> edges;
int visit[N], dist[N], busy[N];
int n, m, q, t;

const int inf = 1e9;
void clear() {
    for(int i = 0; i < N;  i++) {
        visit[i] = 0;
        dist[i] = inf;
        busy[i] = 0;
    }
    edges.clear();
}

void bellmanFord() {
    dist[1] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if(dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
        }
    }
}

void dfs(int u) {
    visit[u] = 1;
    for(auto it : g[u]) {
        if(!visit[it]) dfs(it);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        clear();
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> busy[i];
        cin >> m;
        int u, v;
        for(int i = 1; i <= m; i++) {
            cin >> u >> v;
            int w = (busy[v] - busy[u]);
            edges.push_back(Node(u, v, w*w*w));
            g[u].push_back(v);
        }
        bellmanFord();
        dfs(1);
        cin >> q;
        cout << "Case " << test << ": " << endl;
        for(int i = 1; i <= q; i++) {
            cin >> t;
            if(dist[t] > 2 && dist[t] < inf && visit[t]) cout << dist[t] << endl;
            else cout << "?" << endl;
        }
    }
    return 0;
}
