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
#define INF 0x3f3f3f3f
#define eps 1e-7
#define maxN 5005

int R,C;
string grid[51];
int dist[51][51];
pii source;
vector<int> pairWiseDist;
vector<pii> order;
int X[] = {-1, 0, 0, 1};
int Y[] = {0, -1, 1, 0};

bool feasible(int a, int b) {
    if(a >= 0 && a < R && b >= 0 && b < C) return true;
    return false;
}

void bfs(pii source) {
    queue<pii> pq;
    dist[source.ff][source.ss] = 0;
    pq.push(source);
    while(!pq.empty()) {
        pii node = pq.front();
        pq.pop();
        fri(i, 4) {
            int x = node.ff + X[i];
            int y = node.ss + Y[i];
            int cc = 0;
            if(feasible(x, y)) {
                if(!isdigit(grid[x][y]) || !isdigit(grid[node.ff][node.ss])) cc = 2;
                else if(abs(grid[node.ff][node.ss] - grid[x][y]) == 0) cc = 1;
                else if(abs(grid[node.ff][node.ss] - grid[x][y]) == 1) cc = 3;
                else continue;
                //cout << cc << x << y << endl;
                if(dist[node.ff][node.ss] + cc < dist[x][y]) {
                    dist[x][y] = dist[node.ff][node.ss] + cc;
                    pq.push(mp(x, y));
                }
            }
        }
    }
   /*  fri(i, R) {
        fri(j, C) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    } */
}

bool calDist() {
    fri(i, R) {
        fri(j, C) {
            if(grid[i][j] == '$') {
                //cout << i << " to " << j << "  " << dist[i][j] << " ";
                if(dist[i][j] == INF) return false;
                pairWiseDist.pb(dist[i][j]);
            }
           // cout << endl;
        }
    }
    return true;
}

pii findSource() {
    fri(i, R) {
        fri(j, C) {
            if(grid[i][j] == 'X') {
                source = mp(i, j);
                return source;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> R >> C;
        order.clear();
        pairWiseDist.clear();
        fri(i, R) {
            cin >> grid[i];   
        }
        fri(i, R) {
            fri(j, C) {
               dist[i][j] = INF; 
            }
        }
        source = findSource();
        //cout << source.ff << "  " << source.ss << endl;
        bfs(source);
        if(!calDist()) {
            cout << "-1" << endl;
        } else {
            sort(pairWiseDist.begin(), pairWiseDist.end());
            vector<int> F[2];
            int tsize = pairWiseDist.size();
            int best = INF;
            int t[2];
            fri(i, (1 << tsize)) {
                F[0].clear();
                F[1].clear();
                t[0] = t[1] = 0;
                fri(j, tsize) {
                    F[(i & (1 << j)) != 0].pb(pairWiseDist[j]);
                }
                fri(k, 2) {
                    int j;
                    for(j = 0; j < F[k].size(); j++) {
                        t[k] += (F[k][j]*2);
                    }
                    if(j) t[k] -= F[k][j-1];
                }
                best = min(best, max(t[0], t[1]));
            }
            cout << best << endl;        
        }
    }
    return 0;
}