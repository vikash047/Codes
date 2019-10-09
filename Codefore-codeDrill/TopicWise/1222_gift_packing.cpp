#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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


// ford fulkerson and ddijkastra min cost max flow
struct Edge {
    int from;
    int to;
    int cost;
    int flow = 0;
    int cap;
    int nextEdgeIdx;
    Edge(int _from, int _to, int _cap, int _cost) : from(_from), to(_to), cap(_cap), cost(_cost) {}
};

class MCMF{
    int n, src, sink;
    vector<vector<int>> g;
    vector<int> dist, par, pcfe;
    vector<bool> visit;
    vector<Edge> edges;
    int ec = 0;
    int inf = 2*1e9;
    public:
        MCMF(int src, int sink, int n) {
            this->n = n + 5;
            this->src = src;
            this->sink = sink;
            g.resize(this->n);
            dist.resize(this->n);
            fill(dist.begin(), dist.end(), inf);
            par.resize(this->n);
            fill(par.begin(), par.end(), -1);
            pcfe.resize(this->n);
            fill(pcfe.begin(), pcfe.end(), -1);
            visit.resize(this->n);
            fill(visit.begin(), visit.end(), false);
        }

        void addEdge(int from, int to, int cost, int cap) {
            edges.push_back(Edge(from, to, cap, cost));
            g[from].push_back(ec++);
            edges.push_back(Edge(to, from, 0, -cost));
            g[to].push_back(ec++);
        }

        bool spfa() {
            fill(dist.begin(), dist.end(), inf);
            fill(visit.begin(), visit.end(), false);
            dist[src] = 0;
            queue<int> pq;
            pq.push(src);
            while(!pq.empty()) {
                int node = pq.front();
                pq.pop();
                if(visit[node]) continue;
                visit[node] = true;
                for(auto it : g[node]) {
                    Edge to = edges[it];
                    if(to.cap - to.flow > 0 && dist[to.to] > dist[node] + to.cost) {
                        dist[to.to] = dist[node] + to.cost;
                        par[to.to] = node;
                        pcfe[to.to] = it;
                        pq.push(to.to);
                    }
                }
            }
            return dist[sink] != inf;
        }

        int mcmf() {
            int minCost = 0;
            int maxFlow = 0;
            while (spfa()) 
            {
                int flow = inf;
                int node = sink;
                while(node != src) {
                    flow = min(flow, edges[pcfe[node]].cap - edges[pcfe[node]].flow);
                    node = par[node];
                }
                node = sink;
                while(node != src) {
                    minCost += flow*(edges[pcfe[node]].cost);
                    edges[pcfe[node]].flow += flow;
                    edges[pcfe[node]^1].flow -= flow;
                    node = par[node];
                }
            }
            return -minCost;
        }
};


int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        int n;
        cin >> n;
        int sink = 2*n+1;
        MCMF mcmf(0, sink, 2*n + 2);
        int x;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> x;
                mcmf.addEdge(i, n + j, -x, 1);
            }
        }
        for(int i = 1; i <= n; i++) {
            mcmf.addEdge(0, i, 0, 1);
        }
        for(int i = 1; i <= n; i++) {
            mcmf.addEdge(n + i, sink, 0, 1);
        }
        int res = mcmf.mcmf();
        cout << "Case " << test << ": " << res << endl;
    }
    return 0;
}
