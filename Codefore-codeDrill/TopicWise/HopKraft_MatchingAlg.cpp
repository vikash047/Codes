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

class HopKraft {
    vector<int> matchL, matchR, dist;
    int n, inf;
    vector<vector<int>> g;
    public:
    HopKraft(int n){
        matchL.resize(n+1);
        matchR.resize(n+1);
        dist.resize(n+1);
        g.resize(n+1);
        n = n;
        inf = 1e9;
    }

    void addEdge(int u, int v) {
        g[u].push_back(v);
    }
    bool bfs();
    bool dfs(int u);
    int matching() {
        int match = 0;
        for(int i = 1; i <= n; i++) {
            for(auto it : g[i]) {
                cout << it << " ";
            }
            cout << endl;
        }
        while(bfs()) {
            for(int i = 1; i <= n; i++) {
                if(!matchL[i] && dfs(i)) {
                    match++;
                }
            }
        }
        return match;
    }
};

bool HopKraft :: bfs() {
    queue<int> pq;
    for(int i = 1; i <= n; i++) {
        if(!matchL[i]) {
            pq.push(i);
            dist[i] = 0;
        } else {
            dist[i] = inf;
        }
    }
    // this node is free node and connected to every node in the graph
    dist[0] = inf;
    while(!pq.empty()) {
        int node = pq.front();
        pq.pop();
        for(auto it : g[node]) {
            if(dist[matchR[it]] == inf) {
                dist[matchR[it]] = dist[node] + 1;
                pq.push(matchR[it]);
            }
        }
    }
    return (dist[0] != inf);
}

bool HopKraft :: dfs(int u) {
    if(!u) {
        return true;
    }
    for(auto it : g[u]) {
        if(dist[matchR[it]] == dist[u] + 1 && dfs(matchR[it])) {
            matchL[u] = it;
            matchR[it] = u;
            return true;
        }
    }
    dist[u] = inf;
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        HopKraft hp = HopKraft(n);
        int64 a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int64 l = a[i], r = a[j], m = l^r;
                if(l < m && m < r && l < r) {
                    hp.addEdge(i, j);
                }
                if(l > m && m > r && l > r) {
                    hp.addEdge(i, j);
                }
            }
        }
        int match = hp.matching();
        cout << match/2 << endl;
    }
    return 0;
}
