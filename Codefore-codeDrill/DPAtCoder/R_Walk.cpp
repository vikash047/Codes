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

int mul(int a, int b, int mod = 0) {
    return (int64)a*b%mod;
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
int n;
struct M {
    vector<vector<int>> t;
    M() {
        t.resize(n, vector<int>(n));
    }
    M operator*(const M &b) const {
        M c = M();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    add_slef(c.t[i][j], mul(t[i][k], b.t[k][j], mod), mod);
                }
            }
        }
        return c;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int64 k;
    cin >> n >> k;
    vector<vector<int>>can(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> can[i][j];
        }
    }
    M answer = M();
    M m = M();
    m.t = can;
    for(int i = 0; i < n; i++) answer.t[i][i] = 1;
    //cout << "Hello " << endl;
    while(k) {
        if(k%2) {
            answer = answer*m;
        }
        m = m*m;
        k = k/2;
    }
    int total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            add_slef(total, answer.t[i][j], mod);
        }
    }
    cout << total << endl;
    /* vector<int> dp(n,1);
    for(int64 step = 0; step < k; step++) {
        vector<int> new_dp(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(can[i][j]) {
                    add_slef(new_dp[j], dp[i], mod);
                }
            }
        }
        dp = new_dp;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += dp[i];
    cout << ans << endl;*/
    return 0;
}
