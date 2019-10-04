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

const int N = 50005;
const int inf = 1e9;
vector<int> g[N];
int n, a[N], dist[N], par[N];

void bfs(int s) {
    queue<int> pq;
    pq.push(s);
    dist[s] = 0;
    par[s] = s;
    while(!pq.empty()) {
        int node = pq.front();
        pq.pop();
        //if(visit[node]) continue;
        //visit[node] = true;
        for(auto it : g[node]) {
            if(dist[it] > dist[node] + 1) {
                dist[it] = dist[node] + 1;
                par[it] = node;
                pq.push(it);
            }
        }
    }
}

void printsol(int d, int s) {
    if(d == s) {
        cout << s << " ";
        return;
    }
    printsol(par[d], s);
    cout << d << " ";
}
int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int tst = 1; tst <= t; tst++) {
        cin >> n;
        for(int i = 0; i < N; i++) {
            g[i].clear();
            dist[i] = inf;
            par[i] = -1;
        }
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 2; i <= n; i++) {
            g[a[i-1]].push_back(a[i]);
            g[a[i]].push_back(a[i-1]);
        }
        for(int i = 1; i <= n; i++) {
            sort(g[a[i]].begin(), g[a[i]].end());
        }
        bfs(a[1]);
        cout << "Case " << tst << ": " << endl;
        printsol(a[n], a[1]);
    }
    return 0;
}
