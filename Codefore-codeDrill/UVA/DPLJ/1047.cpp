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

int dp[21][3];

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    for(int ca = 1; ca <= t; ca++) {
        int n;
        cin >> n;
        int a[n][3];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }
       // cout << endl << endl;
        dp[0][0] = a[0][0];
        dp[0][1] = a[0][1];
        dp[0][2] = a[0][2];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                dp[i][j] =  a[i][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
               // cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        int ans = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
        cout << "Case " << ca << ": " << ans << endl;
    }
    return 0;
}
