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

long dp[100002][2];
bool visit[100002];
long dfs(int s, int col[], vector<int> g[], int node) {
    dp[s][0] = 1;
    dp[s][1] = 0;
    visit[s] = true;
    for(int i = 0; i < g[s].size(); i++) {
        int next = g[s][i];
        if(!visit[next]) {
            cout << next << endl;
            dfs(next, col, g, node);
            dp[s][1] *= dp[next][0];
            dp[s][1] += (dp[next][1]*dp[s][0]);
            dp[s][0] *= dp[next][0];
            cout << dp[s][0] << "  " << dp[s][1] << endl;
        }
        
    }
    if(col[s] == 1) {
        dp[s][1] = dp[s][0];
    }else {
        dp[s][0] += dp[s][1];
    }
    cout << "vecrtex " <<  s << "  " << dp[s][0] << "  " << dp[s][1] << endl;
    return dp[s][1];
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    vector<int> g[n];
    int next;
    for(int i = 1; i < n; i++) {
        cin >> next;
        g[i].push_back(next);
        g[next].push_back(i);
    }
    int col[n];
    for(int i = 0; i < n; i++) cin >> col[i];
    memset(dp, -1, sizeof(dp));
    memset(visit, false, sizeof(visit));
    cout << dfs(0, col, g, n) << endl;
    return 0;
}
