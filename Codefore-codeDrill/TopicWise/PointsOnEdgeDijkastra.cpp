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

const int N = 1e5 + 5;
const int inf = 1e9;
int arr[N], dep[N], w[N], vis[N];
vector<pii> g[N];
int n, m, s, l;

class Comp{
    public:
    bool operator()(pii a, pii b) {
        return a.ff > b.ff;
    }
};

void dijkastra(int source, int des, int arr[], int dep[]) {
    for(int i = 1; i <= n; i++) {
        dep[i] = arr[i] = inf;
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<pii, vector<pii>, Comp> pq; 
    arr[source] = 0;
    pq.push(mp(0, source));
    while(!pq.empty()) {
        pii node = pq.top();
        pq.pop();
        if(vis[node.ss]) continue;
        vis[node.ss] = true;
        dep[node.ss] = arr[node.ss];
        //cout << node.ff << endl;
        for(auto it : g[node.ss]) {
            if(arr[it.ff] > dep[node.ss] + w[it.ss]) {
                arr[it.ff] = dep[node.ss] + w[it.ss];
                //cout << "Push " << arr[it.ff] << endl;
                pq.push(mp(arr[it.ff], it.ff));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    cin >> n >> m >> s;
    int u, v;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w[i];
        g[u].push_back(mp(v, i));
        g[v].push_back(mp(u, i));
    }
    cin >> l;
    dijkastra(s, s, arr, dep);
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] == l) res++;
    }
    set<pii> ans;
    for(int i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if(arr[i] < l && arr[i] + w[it.ss] > l && arr[it.ff] + w[it.ss] - (l - arr[i]) >= l) {
                //cout << it.ff << endl;
                if(i < it.ff) {
                    ans.insert(mp(it.ss, l - arr[i]));
                } else {
                    ans.insert(mp(it.ss, w[it.ss] - (l - arr[i])));
                }
            }
        }
    }
    res += ans.size();
    cout << res << endl;
    return 0;
}
