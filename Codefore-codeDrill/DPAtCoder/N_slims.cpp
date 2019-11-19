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

/*vector<string> split(string s, string del) {
        vector<string> ans;
        if(s.size() == 0) {
            return ans;
        }
        size_t pos = 0;
        while(pos = (s.find(del) != string::npos)) {
            string str = s.substr(0, pos);
            ans.push_back(str);
            s.erase(0, pos + del.size());
        }
        return ans;
}*/


/* So problem is to combine two adjuscent value into one 


so it is binary tree to combine and get the result at the root node. but we can create multiple binary tree and which 
would give us min value that is our answer
so at rang l to r we need to fine a k where l, k and k+1,r is min value than l, r
dp[l][r] -> min value of range in bianry tree
 */

const int nax = 405;
const int64 inf = 1e18+5;

int64 dp[nax][nax];
int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int64> ps(n, 0);
    ps[0] = a[0];
    for(int i = 1; i < n; i++) ps[i] += ps[i-1] + a[i];
    auto sum = [&](int L, int R) {
        int64 ans = 0;
        for(int i = L; i <= R; i++) ans += a[i];
        return ans;
    };

    for(int L = n-1; L >= 0; L--) {
        for(int R = L; R < n; R++) {
            if(L == R) {
                dp[L][R] = 0;
            } else {
                dp[L][R] = inf;
                int64 s = sum(L, R);
                for(int i = L; i < R; i++) {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + s);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
