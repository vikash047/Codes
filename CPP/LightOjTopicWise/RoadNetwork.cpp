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


const int maxc = 100;
int m;
vector<pii> adj[maxc];
class comp {
    public:
    bool operator()(pii a, pii b) {
        return a.ff > b.ff;
    }
};

int prims(int v) {
    priority_queue<pii, vector<pii>, comp> pq;
    bool vis[maxc] = {false};
    int res = 0;
    pq.push(mp(0, 1));
    while(!pq.empty()) {
        pii node = pq.top();
        pq.pop();
        int u = node.ss;
        int w = node.ff;
        if(vis[u]) continue;
        res += w;
        vis[u] = true;
        for(int i = 0; i < adj[u].size(); i++) {
            int nextN = adj[u][i].ss;
            if(!vis[nextN]) {
                pq.push(adj[u][i]);
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= v; i++) {
        if(vis[v]) cnt++;
    }
    if(cnt == v) return res;
    return -1;
}
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> m;
        map<string, int> cmp;
        cmp.clear();
        for(int i = 0; i < maxc; i++) adj[i].clear();
        string s1, s2;
        int w;
        int id = 1;
        for(int j = 0; j < m; j++) {
            cin >> s1 >> s2 >> w;
            if(cmp.find(s1) == cmp.end()) {
                cmp[s1] = id;
                id++;
            }
            if(cmp.find(s2) == cmp.end()) {
                cmp[s2] = id;
                id++;
            }
            adj[cmp[s1]].pb(mp(w, cmp[s2]));
            adj[cmp[s2]].pb(mp(w, cmp[s1]));
        }
        //cout << "Hello" << endl;
        int ans = prims(cmp.size());
        if(ans == -1) {
            cout << "Case " << i << ": " << "Impossible" << endl;
        } else {
            cout << "Case " << i << ": " << ans << endl;
        }
    }
    return 0;
}
