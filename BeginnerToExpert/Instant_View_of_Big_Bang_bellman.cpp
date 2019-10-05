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
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w){}

};

const int SZ = 2007;
Edge edges[SZ];
vector<int> adj[SZ], back;
bool visit[SZ];
int N, M, d[SZ], p[SZ];
//const int INF = 1e8+7;

void reset() {
    fri(i, SZ) {
        d[i] = INF;
        p[i] = -1;
        adj[i].clear();
        visit[i] = false;
    }
    back.clear();
}

void relax(int a, int b, int w) {
    if(d[b] > d[a] + w) {
        d[b] = d[a] + w;
        p[b] = a;
    }
}

bool Belleman(int s) {
    fri(k, N-1) {
        fri(eg, M) {
            relax(edges[eg].u, edges[eg].v, edges[eg].w);
        }
    }
    bool isCycle = false;
    fri(eg, M) {
        int a = edges[eg].u, b = edges[eg].v, w = edges[eg].w;
        if(d[b] > d[a] + w) {
            isCycle = true;
            back.pb(a);
        }
    }
    return isCycle;
}

void dfs(int s) {
    visit[s] = true;
    fri(i, adj[s].size()) {
        int next = adj[s][i];
        if(!visit[next]) {
            dfs(next);
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    int x, y, w;
    frei(cs, 1, t) {
        printf("Case %d:",cs);
        cin >> N >> M;
        fri(i, M) {
            cin >> x >> y >> w;
            adj[x].pb(y);
            edges[i] = Edge(x, y, w);
        }
        bool hasNegCycle = Belleman(0); 
        if(!hasNegCycle) {
            printf(" impossible");
        } else {
            fri(i, back.size()) {
                if(!visit[back[i]]) {
                    dfs(back[i]);
                }
                fri(i, N) {
                    if(visit[i]) {
                        printf(" %d",i);
                    }
                }
            }
        }
        cout << endl; 
    }
    return 0;
}
