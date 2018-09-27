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

const int INFI = 100000000;
int E, F, N;
vector<pii> WV;

uint64 solve() {
    int cw = F - E;
    uint64 dp[cw+1];
    dp[0] = 0;
    sort(WV.begin(), WV.end());
    frei(i, 1, cw) dp[i] = INFI;
    //cout << " Hello " << endl;
    frei(i, 1, cw) {
        frei(j, 0, N) {
            if(i >= WV[j].ff) {
                if(dp[i-WV[j].ff] != INFI)
                    dp[i] = min(dp[i], dp[i-WV[j].ff] + WV[j].ss);
            }
        }
    }
    return dp[cw];
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> E >> F >> N;
        int p, w;
        WV.clear();
        frei(i, 1, N) {
            cin >> p >> w;
            WV.pb(mp(w, p));
        }
        int ans = solve();
        if(ans != INFI) {
            cout << "The minimum amount of money in the piggy-bank is " << ans  << "."<< endl;
        } else {
            cout << "This is impossible." << endl;
        }
    }
}