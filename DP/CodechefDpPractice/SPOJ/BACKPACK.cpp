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


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, vmax;
        cin >> vmax >> n;
        int v[n+1], c[n+1], u[n+1], w[n+1];
        int flag[n+1];
        frei(i, 1, n) {
            cin >> w[i] >> c[i] >> u[i];
            flag[i] = 0;
            v[i] = w[i]*c[i];
        }
        v[0] = w[0] = u[0] = v[0] = flag[0] = 0;
        int dp[n+1][vmax+1];
        fri(i, vmax + 1) dp[0][i] = 0;
        
        frei(i, 1, n) {
            if(u[i] != 0) {
                if(!flag[u[i]]) {
                    w[i] = w[i] + w[u[i]];
                }
            }
            frei(j, 1, vmax) {
                if(w[i] > j) dp[i][j] = dp[i-1][j]; 
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
                    if(u[i] != 0 && dp[i][j] != dp[i-1][j]) {
                        flag[u[i]] = 1;                            
                    }
                }
            }
        }
        cout << dp[n][vmax] << endl;
    }
    return 0;
}