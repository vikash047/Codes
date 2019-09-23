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

const int N = 21;
const int M = (1 << 11);
int n, m ,sz = 0;
int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};
vector<pii> v;
char a[N][N];
int visit[N][N], dist[N][N];

bool isFeasible(int x, int  y, int n, int m) {
    return !(x < 0 || x >= n || y < 0 || y >= m); 
}

void bfs(int x, int y, int n, int m) {
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    queue<pii> pq;
    pq.push({x, y});
    visit[x][y] = 1;
    //cout << x << "  " << y << endl;
    while(!pq.empty()) {
        pii node = pq.front();
        pq.pop();
        if(a[node.ff][node.ss] == 'x') {
            continue;
        }
        for(int i = 0; i < 4; i++) {
            int nextX = node.ff + dirX[i];
            int nextY = node.ss + dirY[i];
            //cout << "Points " << nextX << "  " << nextY << endl;
            if(isFeasible(nextX, nextY, n, m) && !visit[nextX][nextY]) {
                dist[nextX][nextY] = dist[node.ff][node.ss] + 1;
                visit[nextX][nextY] = 1;
                pq.push({nextX, nextY});
                //cout << "Points " << nextX << "  " << nextY << endl;
            }
        }
    }
}

int cache[M][N];
int dp(int mask, int lastPoint) {
    if(mask == (1 << sz) - 1) {
        return 0;   
    }
    if(cache[mask][lastPoint] != -1) {
        return cache[mask][lastPoint];
    }
    int ans = 1e9;
    for(int i = 1; i < sz; i++) {
        if(!((mask >> i) & 1)) {
            //cout << i <<  " Points " << endl;
            //cout << v[i].ff << "  " << v[i].ss << endl;
            bfs(v[lastPoint].first, v[lastPoint].second, n, m);
            if(visit[v[i].ff][v[i].ss]) {
                //cout << dist[v[i].ff][v[i].ss] << endl;
                ans = min(ans, dist[v[i].ff][v[i].ss] + dp(mask | (1 << i), i));
            }
        }
    }
    cache[mask][lastPoint] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    while( cin >> m >> n && n != 0) {
        v.clear();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                if(a[i][j] == 'o') {
                    v.push_back({i, j});
                }
            }
        }
        sz = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == '*') {
                    v.push_back({i, j});
                    sz++;
                } 
            }
        }
        memset(cache, -1, sizeof(cache));
        int ans = dp(1, 0);
        if(ans > 1e6) {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}
