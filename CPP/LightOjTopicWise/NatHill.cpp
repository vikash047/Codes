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

const int maxn = 10001;

int n, m;
vector<int> adj[maxn];
bool vis[maxn];
int dis[maxn], low[maxn], disn, parent[maxn];
bool art[maxn];

void reset() {
    for(int i = 0; i < maxn; i++) {
        adj[i].clear();
        vis[i] = false;
        dis[i] = low[i] = 0;
        parent[i] = -1;
        art[i] = false;
    }
    disn = 0;
}
void dfs_art(int u) {
    vis[u] = true;
    dis[u] = low[u] = disn++;
    int childcnt = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int nextNode = adj[u][i];
        if(!vis[nextNode]) {
            childcnt++;
            parent[nextNode] = u;
            dfs_art(nextNode);
            low[u] = min(low[u], low[nextNode]);
            if(parent[u] != -1) {
                if(low[nextNode] >= dis[u]) {
                    art[u] = true;
                }
            }
        }else if(nextNode != parent[u]) {
            low[u] = min(low[u], dis[nextNode]);
        } 
    }
    if(parent[u] == -1 && childcnt > 1) {
        art[u] = true;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        reset();
        cin >> n >> m;
        int x, y; 
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs_art(i);
        }
       // dfs_art(0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(art[i]) ans++;
        }
        cout << "Case " << test << ": " << ans << endl;
    }
    return 0;
}
