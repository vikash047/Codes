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
//#define INF 1000111222
#define eps 1e-7
#define maxN 5005


int n, m, k;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
const int INF = 1<<29;
vector<Edge> adj;
int DMST() {
    int vis[n];
    int dis[n];
    int nE = adj.size();
    int nV = n;
    int Idx[n];
    int parent[n];
    int Res = 0;
    while(true) {
        for(int i = 0; i < nV; i++) {
            vis[i] = -1;
            dis[i] = INF;
            parent[i] = -1;
            Idx[i] = -1;
        }
        for(int i = 0; i < nE; i++) {
            int u = adj[i].u;
            int v = adj[i].v;
            int w = adj[i].w;
            if(u != v && dis[v] > w) {
                parent[v] = u;
                dis[v] = w;
            }
        }
        parent[k] = k;
        dis[k] = 0;
        for(int i = 0; i < nV; i++) {
            if(dis[i] == INF) {
                //cout << "Impossible" << endl;
                return -1;
            }
            Res += dis[i];
        }
        int idx = 0;
        for(int i = 0; i < nV; i++) {
            if(vis[i] == -1) {
                int curr = i;
                while(vis[curr] == -1) {
                    vis[curr] = i;
                    curr = parent[curr];
                }
                if(curr == k || vis[curr] != i) continue; // no cycle
                Idx[curr] = idx;
                for(int u = parent[curr]; u != curr; u = parent[u]) Idx[u] = idx;
                idx++;
            }
        }
        if(idx == 0) break;
        for(int i = 0; i < nV; i++) {
            if(Idx[i] == -1) Idx[i] = idx++;
        }
        for(int i = 0; i < nE; i++) {
            adj[i].u = Idx[adj[i].u];
            adj[i].v = Idx[adj[i].v];
            adj[i].w -= dis[adj[i].v];
        }
        nV = idx++;
        k = Idx[k];
    }
    return Res;
}

// int main(int argc, char const *argv[])
// {
//     /* code */
//    int t;
//    cin >> t;
//    for(int ts = 1; ts <= t; ts++) {
//        cin >> n >> m >> k;
//        int x, y, c;
//        adj.clear();
//        for(int i = 0; i < m; i++) {
//            cin >> x >> y >> c;
//            adj.push_back(Edge(x, y, c));
//        }
//        cout << "Case " << ts << ": ";
//        DMST();

//    } 
//     return 0;
// }

int main(int argc, char const *argv[]) {
    
    return 0;
}
