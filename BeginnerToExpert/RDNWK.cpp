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
#define INF 1<<27
#define eps 1e-7
#define maxN 5005

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    frei(cs, 1, t) {
        int N;
        cin >> N;
        int g[N][N];
        memset(g, 0, sizeof(g));
        fri(k, N) {
            g[k][k] = 0;
            frei(eg, k+1, N) {
                cin >> g[k][eg];
                if(g[k][eg] == -1) g[k][eg] = INF;
                else {
                    g[eg][k] = g[k][eg];
                }
            }
        }
        int P;
        cin >> P;
        int order[P];
        fri(i, P) {
            int x;
            cin >> x;
            order[i] = x-1;
        }
        int64 dist[P+1][N][N];
        int currBest[N][N];
        fri(i, N) {
            fri(j, N){
                dist[0][i][j] = g[i][j];
                currBest[i][j] = g[i][j];
            }
            dist[0][i][i] = 0; 
        }
        frei(p, 1, P) {
            fri(i, N) {
                fri(j, N) {
                    dist[p][i][j] = INF;
                }
                dist[p][i][i] = 0;
            }
        }
        for(int k = 1; k <= P; k++) {
            int via = order[k-1];
            fri(i, N) {
                fri(j, N) {
                    if(dist[k][i][j] > currBest[i][via] + currBest[via][j]) {
                        dist[k][i][j] = currBest[i][via] + currBest[via][j];
                    }
                    if(dist[k][i][j] < currBest[i][j]) currBest[i][j] = dist[k][i][j];
                }
            }
        }
        int q;
        cin >> q;
        cout << "Case " << cs << ": "; 
        fri(i, q) {
            int a, b, c;
            cin >> a >> b >> c;
            b--;
            c--;
            if(dist[a][b][c] == INF) {
                cout << "-1 ";
            }else {
                cout << dist[a][b][c] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
