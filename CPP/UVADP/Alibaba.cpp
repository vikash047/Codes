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
const int maxn = 10000 + 10;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn][2];
int a[maxn], b[maxn];
int main(int argc, char const *argv[])
{
    /* code */
    int n;
    while(scanf("%d",&n) == 1) {
        
        
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        for(int l = 1; l <= n; l++) {
            for(int i = 1; i + l <= n; i++) {
                int j = i + l;
                dp[i][j][0] = min(dp[i+1][j][0] + a[i+1] - a[i], dp[i+1][j][1] + a[j] - a[i]);
                if(dp[i][j][0] >= b[i]) {
                    dp[i][j][0] = inf;
                }
                dp[i][j][1] = min(dp[i][j-1][1] + a[j] - a[j-1], dp[i][j-1][0] + a[j] - a[i]);
                if(dp[i][j][1] >= b[j]) {
                    dp[i][j][1] = inf;
                }
            }
        }

       /* for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << dp[i][j][0] << " ";
            }
            cout << endl;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << dp[i][j][1] << " ";
            }
            cout << endl;
        }*/
        int ans = min(dp[1][n][0], dp[1][n][1]);
        if(ans < inf) {
            cout << ans << endl;
        }else {
            cout << "No solution" << endl;
        }
    }
    return 0;
}
