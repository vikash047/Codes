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

const int64 inf = 1e18+5;

int main(int argc, char const *argv[])
{
    /* code */
    // now weight is 10^9 and value is 10^3 this is min dimension so use it,
    // find out min weight if value is i
    int n, w;
    cin >> n >> w;
    int item[n+1][2];
    for(int i = 1; i <= n; i++) {
        cin >> item[i][0] >> item[i][1];
    }
    int sum_value = 0;
    for(int i = 1; i <= n; i++) {
        sum_value += item[i][1];
    }
    //memset(dp, 0, sizeof(dp));
    //memset(new_dp, 0, sizeof(new_dp));
    vector<int64> dp(sum_value+1, inf);
    vector<int64> new_dp(sum_value+1, inf);
    dp[0] = 0;
    new_dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum_value; j++) {
            if(j >= item[i][1]) {
                new_dp[j] = min(dp[j], dp[j - item[i][1]] + item[i][0]);
            } else {
                new_dp[j] = dp[j];
            }
        }
        dp = new_dp;
    }
    int64 ans = 0;
    /*for(int i = 1; i <= sum_value; i++) {
        cout << dp[i] << " " ;
    }
    cout << endl;*/
    for(int64 i = 1; i <= sum_value; i++) {
        if(dp[i] <= w) {
           // cout << "Hello " << endl;
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
    return 0;
}
