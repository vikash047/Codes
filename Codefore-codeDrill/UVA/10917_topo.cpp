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
vector<pr<int64, int>> g[1001];
int path[1001];
int64 dist[1001];
const int64 inf = 10000000000;
class Comp{
    public:
    bool operator()(pr<int64, int> a, pr<int64, int> b) {
        return a.first > b.first;
    }
};

void dijkastra(int src) 
{
    priority_queue<pr<int64, int>, vector<pr<int64, int>>, Comp> pq;
    memset(dist, inf, sizeof(dist));
    dist[src] = 0;
    pq.push({0, src});
    bool visit[n+1];
    memset(visit, false, sizeof(visit));
    while(!pq.empty()) {
        pr<int64, int> top = pq.top();
        pq.pop();
        int to = top.second;
        int w = top.first;
        if(visit[to]) continue;
        visit[to] = true;
        for(int i = 0; i < g[to].size(); i++) {
            int next = g[to][i].second;
            if(dist[next] > dist[to] + g[to][i].first && !visit[next]) {
                dist[next] = dist[to] + g[to][i].first;
                pq.push({dist[next], next});
            }
        }
    }
}

int countWays(int to) {
    if(path[to] != -1) return path[to];
    int ways = 0;
    for(int i = 0; i < g[to].size(); i++) {
        int fr = g[to][i].second;
        if(dist[fr] > dist[to]) ways += countWays(fr);
    }
    return path[to] = ways;
}

int main(int argc, char const *argv[])
{
    /* code */
    while(true) {
        cin >> n >> m;
        if(n == 0) break;
        int x, y, w;
        for(int i  = 0; i < m; i++) {
            cin >> x >> y >> w;
            g[x].push_back({w, y});
            g[y].push_back({w, x});
        }
        dijkastra(2);
        memset(path, -1, sizeof(path));
        path[1] = 1;
        int ans = countWays(2);
        cout << ans << endl;
        for(int i = 0; i <= n; i++) g[i].clear();
    }
    
    return 0;
}
