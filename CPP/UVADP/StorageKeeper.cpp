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



int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    while(scanf("%d %d", &n, &m) && (n != 0 && m != 0)) {
        int p[m+1];
        for(int i = 1; i <= m; i++) cin >> p[i];
        int dp[35][110];
        
        for(int i = 0; i <= n; i++) dp[0][i] = 0;

        for(int i = 0; i <= m; i++) {
            dp[i][0] = 0x3f3f3f3f;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j  <= n; j++) {
                dp[i][j] = dp[i-1][j];
                for(int k = 0; k < j; k++) {
                    dp[i][j] = max(dp[i][j], min(dp[i-1][k], p[i]/(j-k)));
                }
            }
        }
        if(dp[m][n] == 0) {
            cout << "0" << " 0" << endl;
            continue;
        }
        int l = dp[m][n];
        for(int i = 0; i <= n; i++) dp[0][i] = 0x3f3f3f3f;
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                for(int k = 0; k < j; k++) {
                    if(p[i]/(j - k) >= l)
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + p[i]);
                } 
            }
        }
        cout << l << " " << dp[m][n] << endl;

    }
    return 0;
}
