#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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

const int N = 1000;
const int inf = 1e9;
int n;
vector<int> g[N];
int dist[N], level[N], visit[N], matchU[N], matchV[N], startTime[N], finishTime[N], a[N], b[N], c[N], d[N];

void clear() {
    for(int i = 1; i < N; i++) {
        g[i].clear();
        dist[i] = inf;
        visit[i] = 0;
        matchU[i] = 0;
        matchV[i] = 0;
        level[i] = 0;
    }
}

bool bfs() {
    queue<int> pq;
    for(int i = 1; i <= n; i++) {
        if(matchU[i] == 0) {
            pq.push(i);
            dist[i] = 0;
        } else {
            dist[i] = inf;
        }
    }
    dist[0] = inf;
    while (!pq.empty()) {
        int node = pq.front(); pq.pop();
        if(dist[node] < dist[0]) {
            for(auto it : g[node]) {
                if(dist[matchV[it]] == inf) {
                    dist[matchV[it]] = dist[node] + 1;
                    pq.push(matchV[it]);
                }
            }
        }
    }
    return dist[0] != inf;
}

bool dfs(int u) {
    if(u == 0) return true;
    for(auto it : g[u]) {
        if(dist[matchV[it]] == dist[u] + 1 && dfs(matchV[it])) {
            matchU[u] = it;
            matchV[it] = u;
            return true;
        }
    }
    dist[u] = inf;
    return false;
}

int hopKorp() {
    int matching = 0;
    while(bfs()) {
        for(int u = 1; u <= n; u++) {
            if(matchU[u] == 0 && dfs(u)) {
                ++matching;
            }
        }
    }
    return matching;
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cin >> n;
        int hh, mm;
        for(int i = 1 ; i<= n; i++) {
            scanf("%d:%d %d %d %d %d", &hh, &mm, a+i, b+i, c+i, d+i);
            startTime[i] = hh*60 + mm;
            finishTime[i] = startTime[i] + abs(a[i] - c[i]) + abs(b[i] - d[i]);
        }
        clear();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != j && finishTime[i] + abs(c[i] - a[j]) + abs(d[i] - b[j]) < startTime[j]) {
                    g[i].push_back(j);
                }
            }
        }
        cout << "Case " << test << ": " << n - hopKorp() << endl;
    }
    return 0;
}
