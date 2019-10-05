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

const int N = 2e4 + 5;
vector<int> g[N], trans[N];

int visit[N], scc[N], n, sccCount;
stack<int> st;

void dfs(int u) {
    if(visit[u]) return;
    visit[u] = 1;
    for(auto it : g[u]) {
        dfs(it);
    }
    st.push(u);
}

void dfs2(int u) {
    if(scc[u]) return;
    scc[u] = sccCount;
    for(auto it : trans[u]) {
        dfs2(it);
    }
}

int sccDfs() {
    while (!st.empty())
    {
        st.pop();
    }
    for(int i = 0; i < N; i++) {
        scc[i] = visit[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        if(!visit[i]) dfs(i);
    }
    sccCount = 1;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!scc[node]) dfs2(node);
        sccCount++;
    }
    return sccCount;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        int m;
        cin >> n >> m;
        int u, v;
        for(int i = 0; i < N; i++) {
            g[i].clear();
            trans[i].clear();
        }
        for(int i = 1; i <= m; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            trans[v].push_back(u);
        }
        sccDfs();
        if(sccCount == 2) {
            printf("Case %d: %d\n", test, 0);
            continue;
        }
        int in[n+1], out[n+1];
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for(int i = 1; i <= n; i++) {
            for(auto it : g[i]) {
                if(scc[i] != scc[it]) {
                    out[scc[i]] = 1;
                    in[scc[it]] = 1;
                }
            }
        }
        int rout = 0, rin = 0;
        for(int i = 1; i < sccCount; i++) {
            rout += out[i] == 0 ? 1 : 0;
            rin += in[i] == 0 ? 1 : 0;
        }
        printf("Case %d: %d\n", test, max(rout, rin));
    }
    return 0;
}
