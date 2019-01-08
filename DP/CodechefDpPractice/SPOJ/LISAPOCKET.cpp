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

vector<int> numbers;
vector<int> op;
uint64 inline operation(uint64 a, uint64 b, int op) {
    if(op == 1) {
        return a + b;
    } else {
        return a*b;
    }
}
pair<uint64, uint64> solve() {
    int n = numbers.size();
    pair<uint64, uint64> dp[n][n];
    frei(i, 0, n - 1){
        dp[i][i] = mp(numbers[i], numbers[i]);
    }
   // cout << " size " << n << endl;
    frei(l, 2, n-1) {
        frei(i, 1, n - l) {
            int j = i + l - 1;
            dp[i][j] = mp(0, INT_MAX);
            uint64 t1 = 0, t2 = INT_MAX;
            frei(k, i, j - 1) {
                //cout << "valus of k " << k << endl;
                uint64 costmx = operation(dp[i][k].ff, dp[k+1][j].ff, op[k-1]);
                uint64 costmin = operation(dp[i][k].ss, dp[k+1][j].ss, op[k-1]);
                t1 = max(t1, costmx);
                t2 = min(t2, costmin);
            }
          // cout << " t1 " << t1 << " t2 " << t2 << endl;
            dp[i][j] = mp(t1, t2);
        }
    }
    return dp[1][n-1];
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        numbers.clear();
        numbers.pb(0);
        op.clear();
        fri(i, s.size()) {
           if(i%2) {
               if(s[i] == '+') {
                   op.push_back(1);
               } else {
                   op.push_back(2);
               } 
           } else {
               numbers.pb(s[i] - '0');
           }     
        }
        pair<uint64, uint64> ans = solve();
        cout << ans.ff << " " << ans.ss << endl;
    }
    return 0;
}