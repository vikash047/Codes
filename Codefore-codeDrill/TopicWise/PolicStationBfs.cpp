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

const int N = 100005;
vector<int> g[N];
int visit[N][2];
int dist[N][2];
int ways[N][2];

void bfs(int s, int idx) {
    queue<int> pq;
    pq.push(s);
    dist[s][idx] = 0;
    visit[s][idx] = 1;
    ways[s][idx] = 1;

    while(!pq.empty()) {
        int node = pq.front();
        pq.pop();
        for(int i = 0; i < g[node].size(); i++) {
            int next = g[node][i];
            if(!visit[next][idx]) {
                pq.push(next);
                dist[next][idx] = dist[node][idx] + 1;
                visit[next][idx] = 1;
                ways[next][idx] += ways[node][idx];
            } else if(dist[node][idx] + 1 == dist[next][idx]) {
                ways[next][idx] += ways[node][idx];
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1, 0);
    bfs(n, 1);
    int candidate = 0;
    int rate;
    for(int i = 1; i <= n; i++) {
        if(dist[i][0] + dist[i][1] == dist[n][0]) {
            rate = 1;
            if(i != 1 && i != n) {
                rate = 2;
            }
            int curr = rate*(ways[i][0]*ways[i][1]);
            if(curr > candidate) candidate = curr;
        }
    }
    int totalways = ways[n][0];
    long double ans = (long double)candidate/totalways;
    cout <<fixed<<setprecision(12)<<ans;
    return 0;
}
