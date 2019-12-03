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

void add_slef(int &a, int b, int mod = 0) {
    a += b;
    if(mod > 0 && a >= mod) a -= mod;
}

void sub_slef(int &a, int b, int mod = 0) {
    a -= b;
    if(mod > 0 && a < 0) a += mod;
}

vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while((pos = s.find(del)) != string::npos) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}

const int mod = 1e9 + 7;
const int nax = 3005;
int dp[nax][nax]; // dp [i][j] where prefix length of i and last char j no of ways to put numbers.
int pref[nax][nax];

void solve2(int n, string s) {
    if(n == 1) {
        cout << 1 << endl;
    }
    dp[1][1] = 1;
    for(int len = 2; len <= n; len++) {
        //calculate prefix sum till len -1;
        for(int i = 1; i < len; i++) {
            pref[len-1][i] = (pref[len-1][i-1] + dp[len-1][i])%mod;
        }
        for(int b = 1; b <= len; b++) {
            // we iterate a for some interval  ans dp[len][b] += dp[len-1][a] add some interval so 
            // we can convert it to n^2 so we need some prefix sum
            int L, R;
            if(s[len-2] == '<') {
                L = 1;
                R = b-1;
            } else {
                L = b;
                R = len-1;
            }
            // Now need to optimize this range L, R;
            if(L <= R) {
                add_slef(dp[len][b], (pref[len-1][R] - pref[len-1][L-1]+ mod)%mod, mod);
            }
            /* for(int i = L; i <= R; i++) {
                add_slef(dp[len][b], dp[len-1][i], mod);
            }*/
            /* *for(int a = 1; a <= len - 1; a++) {
                int real_a = a;
                if(a >= b) {
                    ++real_a;
                }
                if(real_a != b) {
                    // means 1 < so I am putting 2 here 1 < 2 and '<' so it is valid case
                    // is 2 < so I am putting 1 here 2 < 1 false and < true so continue no a valid put
                    if((a < b) != (s[len - 2] == '<')) continue;
                    add_slef(dp[len][b], dp[len-1][a], mod);
                }
            }*/
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        add_slef(ans, dp[n][i], mod);
    }
    cout << ans << endl;
}


void solve(int n, string s) {
    if(n == 1) {
        cout << 1 << endl;
    }
    dp[1][1] = 1;
    for(int len = 2; len <= n; len++) {
        for(int b = 1; b <= len; b++) {
            // we iterate a for some interval  ans dp[len][b] += dp[len-1][a] add some interval so 
            // we can convert it to n^2 so we need some prefix sum
            for(int a = 1; a <= len - 1; a++) {
                int real_a = a;
                if(a >= b) {
                    ++real_a;
                }
                if(real_a != b) {
                    // means 1 < so I am putting 2 here 1 < 2 and '<' so it is valid case
                    // is 2 < so I am putting 1 here 2 < 1 false and < true so continue no a valid put
                    if((a < b) != (s[len - 2] == '<')) continue;
                    add_slef(dp[len][b], dp[len-1][a], mod);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        add_slef(ans, dp[n][i], mod);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    string s;
    cin >> n >> s;
    solve2(n, s);
    return 0;
}
