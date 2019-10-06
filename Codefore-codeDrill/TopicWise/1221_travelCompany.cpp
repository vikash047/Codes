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

const int N = 105;

struct Node {
    int u, v;
    int64 w;
    Node(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};
vector<Node> edges;

int n, m, p;

const int64 inf = 1e18; 
bool BellmanFord() {
    int64 dist[N];
    memset(dist, 0, sizeof(dist));
    //dist[edges[0].u] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < edges.size(); j++) {
            int from = edges[j].u;
            int to = edges[j].v;
            int w = edges[j].w;
            if(dist[to] > dist[from] + w) {
                dist[to] = dist[from] + w;
            }
        }
    }
    for(int i = 0; i < edges.size(); i++) {
        int from = edges[i].u;
        int to = edges[i].v;
        int w = edges[i].w;
        if(dist[to] > dist[from] + w) {
            dist[to] = dist[from] + w;
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cin >> n >> m >> p;
        edges.clear();
        int u, v, in, ex;
        for(int i = 1; i <= m; i++) {
            cin >> u >> v >> in >> ex;
            edges.push_back(Node(u,v,p*ex - in));
        }
        if(BellmanFord()) {
            cout << "Case " << test << ": " << "YES" << endl;
        } else {
            cout << "Case " << test << ": " << "NO" << endl;
        }
    }
    return 0;
}
