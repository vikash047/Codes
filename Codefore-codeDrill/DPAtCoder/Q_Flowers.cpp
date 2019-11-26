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

const int nax = 1e5+10;

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int base = 1;
    while(base <= n) {
        base *= 2;
    }
    vector<int64> tree(2*base);
    vector<int> h(n), a(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int64> dp(n+1); // so far height is i waht is max beauty it stores and h <= n so size is n
    for(int i = 0; i < n; i++) {
        // here we can use segment tree and compl is nlogn
        /* for(int j = 0; j < h[i]; j++) {
            dp[h[i]] = max(dp[h[i]], dp[j] + a[i]);
        }*/
        // using segment tree i need max of 0 to h[i]
        int64 best = 0;
        int x = h[i] + base;
        while(x > 1) {
            if(x%2 == 1) {
                best = max(best, tree[x-1]);
            }
            x /= 2;
        }
        dp[h[i]] = best + a[i];
        for(int x = base + h[i]; x >= 1; x /= 2) {
            tree[x] = max(tree[x], dp[h[i]]);
        }
    }
    int64 ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
