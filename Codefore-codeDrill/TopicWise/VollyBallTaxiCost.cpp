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

const int N  = 1005;
const int64 inf = 1e9;
vector<pii> g[N];
int64 arr[N][N];
int n, m;

class Comp {
    public:
    bool operator()(const pair<int64, int> a, const pair<int64, int> b) {
        return a.ff > b.ff;
    }
};

void dijkastra(int src, int des, int64 arr[]) {
    for(int i = 0; i <= N; i++) {
        arr[i] = inf;
    }
    priority_queue<pair<int64, int>, vector<pair<int64, int>>, Comp> pq;
    pq.push(mp(0, src));
    arr[src] = 0;
    while(!pq.empty()) {
        pii node = pq.top();
        pq.pop();
        for(auto it : g[node.ss]) {
            if(arr[it.ff] > arr[node.ss] + it.ss) {
                arr[it.ff] = arr[node.ss] + it.ss;
                pq.push(mp(arr[it.ff], it.ff));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int x, y;
    cin >> n >> m >> x >> y;
    int u, v, w;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(mp(v, w));
        g[v].push_back(mp(u, w));
    }
    for(int i = 1; i <= n; i++) {
        dijkastra(i, i, arr[i]);
    }
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i <= N; i++) g[i].clear();
    int t, c;
    for(int i = 1; i <= n; i++) {
        cin >> t >> c;
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] <= t) {
                g[i].push_back(mp(j, c));
            }
        }
    }
    dijkastra(x, x, arr[0]);
    //cout << endl << endl;
    // for(int i = 1; i <= n; i++) {
    //     cout << arr[0][i] << " ";
    // }
    // cout << endl;
    if(arr[0][y] == inf) {
        cout << "-1" << endl;
        return 0;
    }
    cout << arr[0][y] << endl;
    return 0;
}
