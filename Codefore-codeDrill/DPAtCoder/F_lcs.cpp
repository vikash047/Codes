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


pair<int, pii> maxp(pair<int, pii> a, pair<int, pii> b) {
    if(a.ff > b.ff) {
        return a;
    }
    return b;
}

bool ColRowZero(pair<int, pii> x) {
    return (x.ss.ff == 0 || x.ss.ss == 0);
}

const int inf = 1e9 + 5;
int main(int argc, char const *argv[])
{
    /* code */
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<pair<int,pii>>> dp(n + 1, vector<pair<int, pii>>(m + 1, {0, {0,0}}));
    //dp[0][0] = {0, {0, 0}};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = maxp(dp[i][j], {dp[i-1][j-1].ff + 1, {i-1, j-1}});
            } else {
                dp[i][j] = maxp(dp[i-1][j-1],maxp(dp[i][j-1], dp[i-1][j]));
            }
        }
    }
    pair<int, pii> ans = {0, {0, 0}}, prev;
    /* for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << dp[i][j].ff << " ";
        }
        cout << endl;
    }
    cout << endl << endl;*/
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans = maxp(ans, dp[i][j]);
        }
    }
    
    string ret = "";
    int f = 0;
    while(true) {
        if(ColRowZero(ans)) {
            f++;
        }
        //cout << ans.ff << " " << ans.ss.ff << "  " << ans.ss.ss << endl;
        prev = dp[ans.ss.ff][ans.ss.ss];
        if( (f == 1 && ans.ff == 1)||  (prev.ss.ff != ans.ss.ff && prev.ss.ss != ans.ss.ss)) {
            ret += s[ans.ss.ff];
        }
        ans = prev;
        if(f == 2) break;
    }
    //cout << ans.ff << " " << ans.ss.ff << "  " << ans.ss.ss << endl;
    reverse(ret.begin(), ret.end());
    cout << ret << endl;
    return 0;
}
