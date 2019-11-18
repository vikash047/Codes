#include <bits/stdc++.h>

using namespace std;

#define frei(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define fred(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define fri(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define frd(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )

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
    int n;
    cin >> n;
    double p[n+1];
    for(int i = 1; i<= n; i++) cin >> p[i];
    double dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        double tail = (1 - p[i]);
        double head = p[i];
        dp[0][i] = dp[0][i-1]*tail;
        for(int h = 1; h <= i; h++) {
            dp[h][i] = dp[h-1][i-1]*head + dp[h][i-1]*tail; 
        }
    }
    double ans = 0.0;
    for(int i = n/2 + 1; i <= n; i++) {
        ans += dp[i][n];
    }
    cout << setprecision(9) << ans << endl;
    return 0;
}
