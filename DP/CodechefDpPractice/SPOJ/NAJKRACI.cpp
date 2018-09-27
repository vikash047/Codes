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
#define INF 10000000
#define eps 1e-7
#define maxN 5005

const int maxn = 15001;
const int MOD = 1e9+7;

int n, m;
struct edge {
    int id;
    int next;
    int cost;
    edge(int x, int y, int z){
        id = x;
        next = y;
        cost = z;
    }
};

vector<edge> edges[maxn];
int ans[maxn];
int dist[maxn], dp[maxn], dp2[maxn];
bool visit[maxn];

inline int add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;
}

int solve(int pop) {
    int &ret = dp[pop];
    if(ret != -1) return ret;
    ret = 1;
    fri(i, edges[pop].size()) {
        int next = edges[pop][i].next;
        int ncos = edges[pop][i].cost + dist[pop];
        if(ncos == dist[next]) {
            add(ret, solve(next));
        }
    }
    return ret;
}

void Dijkastra(int start) {
    fri(i, n) {
        dist[i] = INF;
        dp[i] = -1;
        dp2[i] = 0;
        visit[i] = 0;
    }

    priority_queue<pii> pq;
    
    pq.push(mp(0, start));
    dist[start] = 0;
    while(!pq.empty()) {
        pii fr = pq.top();
        pq.pop();
        fr.ff = -fr.ff;
        
        if(dist[fr.ss] != fr.ff) continue;
        
        fri(i, edges[fr.ss].size()) {
            int next = edges[fr.ss][i].next;
            int c = edges[fr.ss][i].cost + fr.ff;
            if(c < dist[next]) {
                dist[next] = c;
                pq.push(mp(-c, next));
            }
        }
    }
    //cout << "End " << endl;
    solve(start);
    pq.push(mp(0, start));
    dp2[start] = 1;
    visit[start] = 0;
    while(!pq.empty()) {
        pii fr = pq.top();
        pq.pop();
        fr.ff = -fr.ff;
        fri(i, edges[fr.ss].size()) {
            int id = edges[fr.ss][i].id;
            int next = edges[fr.ss][i].next;
            int c = edges[fr.ss][i].cost + fr.ff;
            if(dist[next] == c) {
                add(ans[id], ((int64)dp2[fr.ss]*(int64)dp[next])%MOD);
                add(dp2[next], dp2[fr.ss]);
                if(!visit[next]) {
                    pq.push(mp(-c, next));
                    visit[next] = 1;
                }
            }        
        }
    }
    fri(i, n) {
        cout << dp[i] << " ";
    }
    cout << endl;
    fri(i, n) {
        cout << dp2[i] << " ";
    }
    cout << endl;

}

int main() {
    cin >> n >> m;
    fri(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        edges[x].pb(edge(i, y, z));
    }
    fri(i, n) {
        Dijkastra(i);        
    }
    fri(i, m) {
        cout << ans[i] << endl;
    }
}
