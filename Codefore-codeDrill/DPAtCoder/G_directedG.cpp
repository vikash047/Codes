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

const int nax = 1e5 + 5;
vector<int> g[nax];
int dist[nax];
int in_degree[nax];
bool visited[nax];

void dfs(int u) {
    visited[u] = true;
    for(auto next : g[u]) {
        dist[next] = max(dist[next], dist[u] + 1);
        --in_degree[next];
        if(in_degree[next] == 0) dfs(next);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        ++in_degree[b];
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && in_degree[i] == 0) {
            dfs(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    cout << ans << endl;
    return 0;
}
