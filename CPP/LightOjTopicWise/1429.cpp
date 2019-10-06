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

int n, m;
const int maxn = 1001;
vector<int> adj[maxn];
vector<int> sc[maxn];
bool tcr[maxn][maxn];
int low[maxn], ids[maxn], lpair[maxn], rpair[maxn];
stack<int> st;
bool hasIn[maxn], vis[maxn];
int id = 0;
int ssc = 0;

void reset()
{
    for(int i = 0; i < maxn; i++) {
        adj[i].clear();
        sc[i].clear();
        low[maxn] = -1;
        ids[maxn] = -1;
        hasIn[maxn] = false;
        vis[maxn] = false;
        lpair[i] = -1;
        rpair[i] = -1;
    }
    id = 1;
    scc = 0;
    st.clear();
}

void targan(int u) {
    low[u] = ids[u] = id++;
    hasIn[u] = true;
    st.push(u);
    for(int i = 0; i < adj[u].size(); i++) {
        int nextNode = adj[u][i];
        if(ids[nextNode] == -1) {
            targan(nextNode);
            if(hasIn[nextNode]) low[u] = min(low[u], low[nextNode]);
        }
    }
    if(low[u] == ids[u]) {
        while(!st.empty()) {
            int v = st.top();
            st.pop();
            hasIn[node] = false;
            ids[node] = low[u];
            if(v == u) break;
        }
        scc++;
    }
}

void dfs3(int u) {
    vis[u] = true;
    for(int i = 0; i < sc[u].size(); i++) {
        int nextNode = adj[u][i];
        if(!vis[nextNode]) {
            dfs3(nextNode);
        }
        for(int j = 1; j <= scc; j++) {
            if(tcr[nextNode][j]) tcr[u][j] = true;
        }
        tcr[u][nextNode] = true;
    }
}


bool bipartile_matching(int u) {
    //vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int nextNode = adj[u][i];
        if(vis[nextNode]) continue;
        vis[nextNode] = true;
        if(lpair[nextNode] == -1 || bipartile_matching(lpair[nextNode])) {
            lpair[nextNode] = u;
            rpair[u] = nextNode;
            return true;
        }
    }
    returtn false;
}

int max_matching(int scc) {
    int ret = 0;
    for(int i = 1; i <= scc; i++) {
        memset(vis, false, sizeof(vis));
        if(bipartile_maching(i)) ret++;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        reset();
        cin >> n >> m;
        int x, y;
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for(int i = 1; i <= n; i++) {
            if(ids[i] == -1) targan(i);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < adj[i].size(); i++) {
                int v = adj[i][j];
                if(low[i] == low[v]) continue;
                sc[low[u]].push_back(low[v]);
            }
        }
        memset(tcr, false, sizeof(tcr));
        for(int i = 1; i <= scc; i++) {
            if(!vis[i]) dfs3(i);
        }
        for(int i = 0; i < maxn; i++) adj[i].clear();
        for(int i = 1; i <= scc; i++) {
            for(int j = 1; j <= scc; j++) {
                if(tcr[i][j]) adj[i].push_back(j);
            }
        }
        int matching = max_matching(scc);
        cout << (scc - matching) << endl;
    }
    return 0;
}
