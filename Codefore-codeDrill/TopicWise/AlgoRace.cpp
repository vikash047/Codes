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

const int N = 62;
int dist[N][N][N], ans[N][N][N];

int main(int argc, char const *argv[])
{
    /* code */
    int n, m, r, s, t, k;
    cin >> n >> m >> r;
    for(int i = 1; i <= m; i++) {
        for(int c1 = 1; c1 <= n; c1++) {
            for(int c2 = 1; c2 <= n; c2++) {
                cin >> dist[i][c1][c2];
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int mid = 1; mid <= n; mid++) {
            for(int c1 = 1; c1 <= n; c1++) {
                for(int c2 = 1; c2 <= n; c2++) {
                    dist[i][c1][c2] = min(dist[i][c1][c2], dist[i][c1][mid] + dist[i][mid][c2]);
                }
            }
        }
    }
    for(int c1 = 1; c1 <= n; c1++) {
        for(int c2 = 1; c2 <= n; c2++) {
            ans[c1][c2][0] = 2e9;
            for(int car = 1; car <= m; car++) {
                ans[c1][c2][0] = min(ans[c1][c2][0], dist[car][c1][c2]);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int c1 = 1; c1 <= n; c1++) {
            for(int c2 = 1; c2 <= n; c2++) {
                ans[c1][c2][k] = 2e9;
                for(int mid = 1; mid <= n; mid++) {
                    ans[c1][c2][k] = min(ans[c1][c2][k], ans[c1][mid][k-1] + ans[mid][c2][0]);
                }
            }
        }
    }
    while(r--) {
        cin >> s >> t >> k;
        k = min(k, n);
        cout << ans[s][t][k] << endl;
    }    
    return 0;
}
