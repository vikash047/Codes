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
const int N = 1e4;
int n, m;
vector<int> adj[N], radj[N], tree[N], reachAdj[N];
int tcr[N][N];
int number_scc, node_scc[N], matchU[N], matchV[N];
bool visit[N];
stack<int> st;

void clear() {
    for(int i = 0; i < N; i++) {
        adj[i].clear();
        radj[i].clear();
        tree[i].clear();
        reachAdj[i].clear();
        visit[i] = false;
        node_scc[i] = 0;
        matchU[i] = -1;
        matchV[i] = -1;
    }
    memset(tcr, 0, sizeof(tcr));
    while(!st.empty()) st.pop();
    number_scc = 1;
}

void dfs1(int u) {
    visit[u] = true;
    for(auto it : adj[u]) {
        if(!visit[it]) dfs1(it);
    }
    st.push(u);
}

void dfs2(int u, int idx) {
    node_scc[u] = idx;
    visit[u] = true;
    for(auto it : radj[u]) {
        if(!visit[it]) dfs2(it, idx);
    }
}

int scc() {
    for(int i = 1; i <= n; i++) {
        if(!visit[i]) dfs1(i);
    }
    memset(visit, false, sizeof(visit));
    while (!st.empty())
    {
        int node = st.top(); st.pop();
        if(!visit[node]) {
            dfs2(node, number_scc);
            number_scc++;
        }
    }
    return number_scc;
}

void dfs3(int u) {
    visit[u] = true;
    for(auto it : tree[u]) {
        if(!visit[it]) dfs3(it);
        for(int i = 1; i < number_scc; i++) {
            if(tcr[it][i]) tcr[u][i] = 1;
        }
        tcr[u][it] = 1;
    }
}

bool bpm(int u) {
    for(auto it : reachAdj[u]) {
        // Important lines if you have already visited means you come via that node on this node. if you 
        // you are going to visit this node means you can not come via this node otherwise it would follow the same path.
        if(visit[it]) continue;
        visit[it] = true;
        if(matchV[it] == -1 && bpm(matchV[it])) {
            matchV[it] = u;
            matchU[u] = it;
            return true; 
        }
    }
    return false;
}

int max_matching() {
    int ans = 0;
    for(int i = 1; i < number_scc; i++) {
        memset(visit, false, sizeof(visit));
        ans += bpm(i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cin >> n >> m;
        int u, v;
        clear();
        for(int i = 1; i <= m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        int sc = scc();
        for(int i = 1; i <= n; i++) {
            for(auto it : adj[i]) {
                if(node_scc[i] != node_scc[it]) {
                    tree[node_scc[i]].push_back(node_scc[it]);
                }
            }
        }
        memset(visit, false, sizeof(visit));
        for(int i = 1; i < number_scc; i++) if(!visit[i]) dfs3(i);
        for(int i = 1; i < number_scc; i++) {
            for(int j = 1; j < number_scc; j++) {
                if(tcr[i][j]) {
                    reachAdj[i].push_back(j);
                }
            }
        }
        int matches = max_matching();
        cout << "Case " << test << ": " << number_scc - matches - 1 << endl;
    }
    return 0;
}
