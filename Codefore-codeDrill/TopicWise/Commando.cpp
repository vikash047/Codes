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
int n, m, s, d;
vector<int> g[N];

void bfs(int s, vector<int> &dist)
{
    bool visit[n+1];
    for(int i = 0; i <= n;  i++) {
        visit[i] = false;
    }
    queue<int> pq;
    pq.push(s);
    dist[s] = 0;
    visit[s] = true;
    while(!pq.empty()) {
        int node = pq.front();
        pq.pop();
        for(auto it : g[node]) {
            if(!visit[it]) {
                dist[it] = dist[node] + 1;
                visit[it] = true;
                pq.push(it);
            }
        }
    }
}



int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int tst = 1; tst <= t; tst++) {
        cin >> n >> m;
        int u, v;
        for(int i = 1; i <= m; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cin >> s >> d;
        cout << "Case " << tst << ": ";
        vector<int> sd(n+1, 0), dd(n+1, 0);
        bfs(s, sd);
        bfs(d, dd);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, sd[i] + dd[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
