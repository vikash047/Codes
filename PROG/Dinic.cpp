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

struct Edge {
    int v;
    int f;
    int rev;
    int c;
};

class Dinic {
    int V;
    vector<Edge> *adj;
    int *level;
    public:
    Dinic(int vertex) {
        this->V = vertex;
        adj = new vector<Edge>[V];
        level = new int[V];
    }
    void addEdge(int x, int y, int c) {
        Edge a{y, 0, adj[y].size(), c};
        Edge b{x, 0, adj[x].size(), 0};
        adj[x].pb(a);
        adj[y].pb(b);
    }

    bool bfs(int s, int t) {
        fri(i, V) level[i] = -1;
        queue<int> pq;
        pq.push(s);
        level[s] = 0;
        while(!pq.empty()) {
            int node = pq.front();
            pq.pop();
            fri(i, adj[node].size()) {
                Edge next = adj[node][i];
                if(level[next.v] < 0 && next.f < next.c) {
                    level[next.v] = level[node] + 1;
                    pq.push(next.v);
                }
            }
        }
        return (level[t] > 0);
    }

    int dfs(int node, int flow, int t) {
        if(node == t) return flow;
        fri(i, adj[node].size()) {
            Edge next = adj[node][i];
            if(level[next.v] == level[node] + 1 && next.c > next.f) {
                int currFlow = min(flow, next.c - next.f);
                int tempFlow = dfs(next.v, currFlow, t);
                if(tempFlow > 0) {
                    next.f += tempFlow;
                    adj[next.v][next.rev].f -= tempFlow;
                    return tempFlow;
                }
            }
        }
        return 0;
    }
    int dinic(int s, int t) {
        if(s == t) return 0;
        int ans = 0;
        while(bfs(s, t)) {
            while(int flow = dfs(s, INT_MAX, t)) {
                ans += flow;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
