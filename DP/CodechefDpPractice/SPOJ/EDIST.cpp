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
int dp[2001][2001];

string s1, s2;

int solve() {
    int n = s1.size();
    int m = s2.size();
    frei(i, 0, n) dp[0][i] = i;
    frei(i, 0, m) dp[i][0] = i;
    frei(i, 1, m) {
        frei(j, 1, n) {
            if(s2[i-1] == s1[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    /* fri(i, m+1) {
        fri(j, n+1) {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    } */
    return dp[m][n];
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> s1 >> s2;
        cout << solve() << endl;
    }
}