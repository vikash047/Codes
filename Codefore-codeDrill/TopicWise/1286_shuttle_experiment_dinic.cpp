#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//#define fill(ar, val) memset(ar, val, sizeof(ar))

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

const int N = 105;
struct Edge{
    int to;
    int from;
    int64 cap;
    int64 flow = 0;

    Edge(int _from, int _to, int64 _cap): to(_to), from(_from), cap(_cap) {} 
};

const int64 inf = 1e18;

// Dinic max flow algorithm applied here
class Dinic{
    int n, src, sink;
    vector<vector<int>> g;
    vector<Edge> edges;
    int m = 0;
    vector<int> level, ptr;
    queue<int> pq;
    public:
    Dinic(int n, int src, int sink) {
        this->n = n + 5;
        this->src = src;
        this->sink = sink;
        this->level.resize(this->n);
        this->ptr.resize(this->n);
        this->g.resize(this->n);
    }

    void addEdge(int from, int to, int64 cap) {
        edges.push_back(Edge(from, to, cap));
        //cout << "He llo " << endl;
        g[from].push_back(m++);
        edges.push_back(Edge(to, from, 0));
        g[to].push_back(m++);
       // cout << "Hello " << endl;
    }

    bool bfs() {
        while(!pq.empty()) {
            int node = pq.front();
            pq.pop();
            for(auto it : g[node]) {
                Edge to = edges[it];
                if(to.cap - to.flow == 0) continue;
                if(level[to.to] == -1) {
                    level[to.to] = level[node] + 1;
                    pq.push(to.to);
                }
            }
        }
        return level[sink] != -1;
    }

    int64 dfs(int s, int64 flow) {
        if(flow == 0) return 0;
        if(s == sink) return flow;
        for(int &cid = ptr[s]; cid < g[s].size(); cid++) {
            int id = g[s][cid];
            Edge to = edges[id];
            if(level[to.to] != level[s] + 1 || to.cap - to.flow == 0) continue;
            int64 tempFlow = dfs(to.to, min(flow, to.cap - to.flow));
            if(tempFlow == 0) continue;
            edges[id].flow += tempFlow;
            edges[id^1].flow -= tempFlow;
            return tempFlow;
        }
        return 0;
    }

    int64 getFlow() {
        int64 maxFlow = 0;
        while (true)
        {
            fill(level.begin(), level.end(), -1);
            level[src] = 0;
            while(!pq.empty()) pq.pop();
            pq.push(src);
            if(bfs() == false) break;
            fill(ptr.begin(), ptr.end(), 0);
            //cout << "Hello " << endl;
            while(int64 flow = dfs(src, inf)) {
                maxFlow += flow;
                //cout << flow << endl;
            }
        }
        return maxFlow;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        int m, n;
        cin >> m >> n;
        int src = 0; 
        int sink = n + 2*m + 2;
        Dinic dinic(n + m*2, src, sink);
        int ecost;
        int64 ans = 0;
        for(int i = 1; i <= m; i++) {
            cin >> ecost;
            //cout << ecost << endl;
            dinic.addEdge(src, i, ecost);
            ans += ecost;
        }
        for(int i = 1; i <= n; i++) {
            cin >> ecost;
            dinic.addEdge(m + i, sink, ecost);
        }
        for(int i = 1; i <= m; i++) {
            int q;
            cin >> q;
            while(q--) {
                cin >> ecost;
                dinic.addEdge(i, m + ecost, inf);
            }
        }
        cout << ans << endl;
        cout << "Case " << test << ": " << (ans - (int)dinic.getFlow()) << endl;
    }
    return 0;
}
