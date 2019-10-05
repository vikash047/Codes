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
const int maxm=40010;
int n, m, k;

struct Edge {
    int to;
    int next;
} edge[maxm];

int gr[501][501];
int cnt = 0;
int head[maxm];
int vis[maxm];
int match[maxm];
int odd, even;
//int n, m, k;
void init(){
    memset(gr, 0, sizeof(gr));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int dirx[] = {-2, -2, 2, 2, 1, -1, 1, -1};
int diry[] = {-1, 1, -1, 1, -2, -2, 2, 2};
void getMap() {
    cin >> n >> m >> k;
    int x, y;
    init();
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        gr[x][y] = -1;
    }
    //int even = 0, odd = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(gr[i][j] == 0) {
                if((i+j)&1) {
                    gr[i][j] = ++odd;
                } else {
                    gr[i][j] = ++even;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(gr[i][j] != -1 && (i+j)&1) {
                for(int k = 0; k < 8; k++) {
                    int nextX = i + dirx[k];
                    int nextY = j + diry[k];
                    if(nextX > 0 && nextX <= n && nextY > 0 && nextY <= m && gr[nextX][nextY] != -1) {
                        addEdge(gr[i][j], gr[nextX][nextY]);
                    }
                }
            }
        }
    }
}

bool dfs(int node) {
    for(int i = head[node]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(vis[v] == 0) {
            vis[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = node;
                return true;
            }
        }
    }
    return false;
}


int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++) {
        getMap();
        int ans = 0;
        memset(match, -1, sizeof(match));
        for(int i = 1; i <= odd; i++) {
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) {
                ans++;
            }
        }
        printf("Case %d: %d\n", test, n*m - k - ans);
    }
    return 0;
}
