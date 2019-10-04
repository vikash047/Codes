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

const int N = 505;
const int M = 1e5+5;
vector<pii> g[N];
vector<int> edges;
int U[M], V[M], P[N], visit[N];
int n, m;
int findLoop(int u, int edgeIdx) {
    if(visit[u] == 1) {
        edges.push_back(edgeIdx);
        int p = U[edgeIdx];
        while(p != u) {
            edges.push_back(P[p]);
            p = U[P[p]];
        }
        return 1;
    }
    if(visit[u] == 2) {
        return 0;
    }
    visit[u] = 1;
    P[u] = edgeIdx;
    for(auto it : g[u]) {
        if(findLoop(it.ff, it.ss)) {
            return 1;
        }
    }
    visit[u] = 2;
    return 0;
}

bool checkLoop() {
    memset(visit, 0, sizeof(visit));
    for(int i = 1; i <= n; i++) {
        if(!visit[i]) {
            if(findLoop(i, -1))
                return 1;
        }
    }
    return 0;
}

int findLoop2(int u, int forb) {
    if(visit[u] == 1) {
        return 1;
    }
    if(visit[u] == 2) {
        return 0;
    }
    visit[u] = 1;
    for(auto it : g[u]) {
        if(it.ss == forb) continue;
        if(findLoop2(it.ff, forb)) {
            return 1;
        }
    }
    visit[u] = 2;
    return 0;
}

bool checkLoop2(int u) {
    memset(visit, 0, sizeof(visit));
    for(int i = 1; i <= n; i++) {
        if(!visit[i] && findLoop2(i, u)) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> U[i] >> V[i];
        g[U[i]].push_back(mp(V[i], i));
    }
    if(!checkLoop()) {
        cout << "YES" << endl;
    } else {
        bool f = true;
        for(auto it : edges) {
            if(checkLoop2(it)) {
                cout << "YES" << endl;
                f = false;
                break;
            }
        }
        if(f) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
