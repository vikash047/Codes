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
    if(mod > 0) {
        return (int)((int64)a*b%mod);
    }
    return a*b;
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

int main(int argc, char const *argv[])
{
    /* code */
    //return 0;
    int n, c;
    cin >> n >> c;
    vector<int> v(n, 0);
    vector<int> w(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> w[i];
    vector<int> dp(c+1, 0);
    for(int i = 0; i < n; i++) {
        vector<int> new_dp(c+1, 0);
        for(int j = 0; j <= c; j++) {
            if(w[i] <= j) {
                new_dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
            } else {
                new_dp[j] = dp[j];
            }
        }
        dp = new_dp;
    }
    int res = 0;
    for(int i = 0; i <= c; i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}
