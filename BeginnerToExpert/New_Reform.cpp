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

int n, m;

bool dfs(int source, vector<int> adj[], bool visit[], int p, bool *f) {
    visit[source] = true;
    fri(i, adj[source].size()) {
        int next = adj[source][i];
        if(!visit[next]) {
            dfs(next, adj, visit, source, f);
        }else if(next != p) {
            *f = true;
        }
    }
} 

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m;
    vector<int> adj[n];
    int x, y;
    fri(i, m) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int cnt = 0;
    bool visit[n];
    memset(visit, false, sizeof(visit));
    fri(i, n) {
        if(!visit[i]) {
            bool f = false;
            dfs(i, adj, visit, -1, &f);
            if(!f) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
