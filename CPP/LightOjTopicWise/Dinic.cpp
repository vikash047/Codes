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

struct Edge{
    int u, v, cap = 0, flow = 0;
    Edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}
}

class Dinic {
    public:
        int src;
        int sink;
        int nNode;
        int bi;
        const uint64 max_flow = INF;
        vector<Edge> edges;
        vector<vector<int>> adj;
        vector<int> level;
        vector<int> ptr;
        queue<int> pq;
        int m = 0;
        Dinic(int src, int sink, int nNode, int bi) {
            src = src;
            sink = sink;
            nNode = nNode;
            bi = bi;
            adj.resize(nNode);
            level.resize(nNode);
            ptr.resize(nNode);
        }
        void addEdge(int u, int v, uint64 cap) {
            edges.push_back(Edge(u, v, cap));
            edges.push_back(v, u, bi ? cap : 0);
            adj[u].push_back(m);
            adj[v].push_back(m+1);
            m += 2;
        }
        bool bfs() {
            while(!pq.empty()) {
                int node = pq.front();
                pq.pop();
                for(int i = 0; i < adj[node].size(); i++) {
                    int id = adj[node][i];
                    if(edges[id].cap - edges[id].flow <= 0) continue;
                    if(level[edges[id].v] != -1) continue;
                    level[edges[id].v] = level[node] + 1;
                    pq.push(edges[id].v);
                }
            }
            return level[sink] != -1;
        }
        uint64 dfs(int node, uinty64 flow) {
            if(flow == 0) return 0;
            if(node == sink) return flow;
            for(int id = ptr[node]; id < adj[node].size(); id++) {
                ptr[node]++;
                int cid = adj[node][id];
                int v = edges[cid].v;
                if(level[v] != level[node] + 1 || edges[cid].cap - edges[cid].flow <= 0) {
                    continue;
                }
                uiint64 tr = dfs(edges[node].v, min(flow, edges[cid].cap - edges[cid].flow));
                if(tr == 0) continue;
                edges[cid].flow += tr;
                edges[cid^1].flow -= tr;
                return tr;
            }
            return 0;
        }

        uint64 flow() {
            uint64 f = 0;
            while(true) {
                fill(level.begin(), level.end(), -1);
                level[src] = 0;
                pq.push(src);
                if(!bfs()) {
                    break;
                }
                fill(ptr.begin(), ptr.end(), 0);
                while(uint64 ret = dfs(src, max_flow)) {
                    f += ret;
                }
            }
            return f;
        }

};

int main(int argc, char const *argv[])
{
    /* code */
    
    return 0;
}
