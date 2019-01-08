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
#define INF 1 << 29
#define eps 1e-7
#define maxN 5005

int hire, ser, sal;
int month[25];
int m;

int solve(int prev, int day, int tot) {
    if(day == m) return tot;
    int curr = month[day];
    int ans = INF;
    if(prev > curr) {
        ans = min(solve(prev, day + 1, tot + prev*sal), solve(curr, day + 1, tot + (curr*sal + (prev - curr)*ser)));
        for(int i = 1; i < prev-curr; i++) {
            ans = min(ans, solve(curr + i, day + 1, tot + (curr + i)*sal + (prev - curr - i)*ser));
        }
    } else {
        ans = solve(curr, day + 1, tot + curr*sal + (curr - prev)*hire);
    }
    return ans;
}

int64 solveByDP() {
    int mx = 0;
    fri(i, m) mx = max(mx, month[i]);
    int64 dp[25][mx+1];
    fri(i, month[0]) dp[0][i] = INF;
    frei(i, month[0], mx) dp[0][i] = i*(sal + hire);
    frei(i, 1, m-1) {
        frei(j, 0, mx) dp[i][j] = INF;
    }
    frei(i, 1, m-1) {
        frei(j, 1, mx) {
            dp[i][j] = INF;
            if(month[i] > j) continue;
            frei(k, 1, mx) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + j*sal + (j > k ? (j-k)*hire :(k - j)*ser));
            }
        }
    }
    int64 ans = INF;
    frei(i, 1, mx) {
        ans = min(ans, dp[m-1][i]);
    }
    return ans;
}

int main() {
    int k = 1;
    while(1) {
        cin >> m;
        if(m == 0) break;
        cin >> hire >> sal >> ser;
        fri(i, m) cin >> month[i];
        int ans = solveByDP();
        cout << "Case " << k << ", " <<  "cost = $" << ans << endl;
        k++;
    }
}