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
int dp[1 << 22];
int solve(int index, int mask, int n, vector<vector<int>> can) {
    if(index == n || mask == (1 << n)) {
        return 1;
    }
    if(dp[mask] != 0) {
        return dp[mask];
    }
    int ans = 0;
    for(int i = 0; i < can.size(); i++) {
        if(can[index][i] && !(mask & (1 << i))) {
            //cout << index << "  " << i << " " << mask << endl;
            add_slef(ans, solve(index + 1, mask ^ (1 << i), n, can), mod);
        }
    }
    dp[mask] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<vector<int>> can(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> can[i][j];
    }
    vector<int> dp(1 << n);
    dp[0] = 1;
    for(int mask = 0; mask < (1 << n)-1; mask++) {
        int men = __builtin_popcount(mask);
        for(int i = 0; i < n; i++) {
            if(can[men][i] && !(mask & (1 << i))) {
                int m2 = mask ^(1 << i);
                add_slef(dp[m2], dp[mask], mod);
            }
        }
    }
    cout << dp[(1 << n)-1] << endl;
    //cout << solve(0, 0, n, can) << endl;
    return 0;
}
