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
#define INF 1000111222
#define eps 1e-7
#define maxN 5005


int n, width, height, dp[601][601], w[601], h[601];

int solve() {
    frei(i, 0, width) dp[0][i] = 0;
    frei(i, 0, height) dp[i][0] = 0;
    dp[1][1] = 1;
    frei(i, 1, height) {
        frei(j, 1, width) {
            if(dp[i][j] < 0 )dp[i][j] = i*j;
            frei(k, 1, n) {
                if(w[k] <= j && h[k] <= i) {
                    dp[i][j] = min(dp[i][j], dp[h[k]][j - w[k]] + dp[i - h[k]][j]);
                    dp[i][j] = min(dp[i][j], dp[i - h[k]][w[k]] + dp[i][j - w[k]]);
                }
            }
        }
    }
    return dp[height][width];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> width >> height >> n;
        memset(dp, -1, sizeof(dp));
        frei(i, 1, n) {
            cin >> w[i] >> h[i];
            dp[h[i]][w[i]] = 0;
        }
        cout << solve() << endl;
    }
}