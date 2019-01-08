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

int k, n, m;
int cost[55], value[55];
int dp[25][105][55][3];
/* solution hide in this logic 
    dp[L][B][A][1] = dp[L-1][B-cost[A]][A][1]*/
int solve() {

    frei(i, 1, k) {
        frei(b, 1, m) {
            frei(d, 1, n) {
                dp[i][b][d][0] = dp[i-1][b][d][0];
                if(b >= cost[d]) {
                    dp[i][b][d][1] = max(dp[i][b][d][1], dp[i-1][b-cost[d]][d][0]);
                }
            }
        }
    }
}    
int main() {
    while(1) {
        cin >> k >> n >> m;
        if(k + n + b == 0) break;
        frei(i, 1, n) cin >> cost[i] >> value[i];
        
    }
}