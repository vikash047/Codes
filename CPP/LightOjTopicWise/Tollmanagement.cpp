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

const int maxn = 10002;
const int INF = 1 << 28;

int n, m, s, t, p, x, y, c;
vector<pii> adj[maxn];
vector<pii> adjRev[maxn];
int dis[2][maxn];


struct edge {
    int u, v, c;
} inp[5*maxn + 5];

struct Graph {
    int node, w;
    Graph() {}
    Graph(int u, int c) {
        node = u;
        w = c;
    }
    bool operator < (const Graph& g) const {
        return g.w < w;
    }
};

void clear() {
    for(int i = 0; i < maxn; i++) {
        adj[i].clear();
        adjRev[i].clear();
        for(int j = 0; j < 2; j++) dis[j][i] = INF;
    }
}

void input() {
    cin >> n >> m >> s >> t >> p;
    clear();
    for(int i = 1; i <= m; i++) {
        cin >> x >> y >> c;
        adj[x].push_back(mp(y, c));
        adjRev[y].push_back(mp(x, c));
        inp[i].u = x;
        inp[i].v = y;
        inp[i].c = c;
    }
}

void dijkastra_forward() {
    priority_queue<Graph> pq;
    pq.push(Graph(s, 0));
    while(!pq.empty()) {
        Graph nn = pq.top(); pq.pop();
        if(dis[0][nn.node] != INF) continue;
        else dis[0][nn.node] = nn.w;

        for(int i = 0; i < adj[nn.node].size(); i++) {
            int nextNode = adj[nn.node][i].ff;
            int dist = nn.w + adj[nn.node][i].ss;
            if(dis[0][nextNode] != INF) continue;
            pq.push(Graph(nextNode, dist));
        }
    }
}

void dijkastra_backward() {
    priority_queue<Graph> pq;
    pq.push(Graph(t, 0));
    while(!pq.empty()) {
        Graph nn = pq.top(); pq.pop();
        if(dis[1][nn.node] != INF) continue;
        else dis[1][nn.node] = nn.w;
        for(int i = 0; i < adjRev[nn.node].size(); i++) {
            int nextNode = adjRev[nn.node][i].ff;
            int dist = adjRev[nn.node][i].ss + nn.w;
            if(dis[1][nextNode] != INF) continue;
            pq.push(Graph(nextNode, dist));
        }
    }
}

void print() {
    for(int i = 1; i <= n; i++) {
        cout << dis[0][i] << "  " << dis[1][i] << endl;
    }
    cout << endl;
}

int solve() {
    input();
    dijkastra_forward();
    dijkastra_backward();
    int ans = -1;
    //print();
    for(int i = 1; i <= m; i++) {
        int x = inp[i].u;
        int y = inp[i].v;
        int c = inp[i].c;
        if(dis[0][x] == INF || dis[1][y] == INF) continue;
        if(dis[0][x] + dis[1][y] + c > p) continue;
        if(ans < c) ans = c;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int test;
    cin >> test;
    for(int cs = 1; cs <= test; cs++) {
        printf("Case %d: %d\n", cs, solve());
    }
   
    return 0;
}
