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

const int N = 3*1e4+5;

vector<pii> g[N];
int dp[N];
int n;

void bfs(int s) {
    queue<int> pq;
    pq.push(s);
    dp[s] = 0;
    bool visit[n+1];
    for(int i = 0; i <= n; i++) {
        visit[i] = false;
    }
    while(!pq.empty()) {
        int node = pq.front();
        pq.pop();
        if(visit[node]) continue;
        visit[node] = true;
        //cout << node << endl;
        for(auto it : g[node]) {
            //cout << it.ff  << "  " << it.ss << "  "  << visit[it.ff] << endl;
            if(visit[it.ff]) continue;
            
            dp[it.ff] = dp[node] + it.ss;
            pq.push(it.ff);
        }
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        for(int j = 0; j <= N; j++){
            g[j].clear();
            dp[i] = 0;
        } 
        int u, v, w;
        for(int j = 1; j < n; j++) {
            cin >> u >> v >> w;
            g[u].push_back(mp(v, w));
            g[v].push_back(mp(u, w));
        }
        bfs(0);
        int max_dist = -1, node;
        for(int j = 0; j < n; j++) {
            if(max_dist < dp[j]) {
                max_dist = dp[j];
                node = j;
            }
        }
        bfs(node);
        for(int j = 0; j < n; j++) {
            if(max_dist < dp[j]) {
                max_dist = dp[j];
                node = j;
            }
        }
        cout << "Case " << i << ": " << max_dist << endl;
    }
    return 0;
}
