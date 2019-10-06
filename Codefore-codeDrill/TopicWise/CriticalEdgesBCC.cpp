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

const int N = 705;
vector<int> g[N];
vector<pii> bridges;

bool comp(const pii a, const pii b) {
    if(a.ff == b.ff) {
        return a.ss < b.ss;
    }
    return a.ff < b.ff;
}

int visit[N], tin[N], tout[N], minAcc[N], T = 0;
void dfs(int u, int par) {
    tin[u] = ++T;
    minAcc[u] = tin[u];
    visit[u] = 1;
    for(auto it : g[u]) {
        if(it == par) {
            continue;
        } 
        if(visit[it]) {
            minAcc[u] = min(minAcc[u], tin[it]);
            continue;
        }else {
            dfs(it, u);
            minAcc[u] = min(minAcc[u], minAcc[it]);
            if(tin[u] < minAcc[it]) {
                bridges.push_back(mp(u, it));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int ts = 1; ts <= t; ts++) {
        int n, m;
        cin >> n >> m;
        int x, y;
        for(int i = 0; i < N; i++) {
            g[i].clear();
            visit[i] = false;
        }
        bridges.clear();
        for(int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1, 0);
        sort(bridges.begin(), bridges.end(), comp);
        cout << "Caso #" << ts << endl;
        if(bridges.size() > 0) {
            cout << bridges.size() << endl;
            for(int i = 0; i < bridges.size(); i++) {
                cout << bridges[i].ff << " " << bridges[i].ss << endl;
            }
        } else {
            cout << "Sin bloqueos" << endl;
        }
    }
    return 0;
}
