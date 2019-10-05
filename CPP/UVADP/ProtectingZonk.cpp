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

vector<int> GR[10001];
int dp[10001][4];
int c1, c2, n;

int dfs(int u, int fa) {
    dp[u][0] = dp[u][3] = 0;
    dp[u][1] = c1;
    dp[u][2] = c2;
    int sum = 0, minA = INT_MAX;
    for(int i = 0; i < GR[u].size(); i++) {
        int nextNode = GR[u][i];
        if(nextNode == fa) continue;
        dfs(nextNode, u);
        int t = min(dp[nextNode][0], dp[nextNode][1], dp[nextNode][2]);
        dp[u][0] += dp[nextNode][1];
        dp[u][1] += t;
        dp[u][2] += min(t, dp[nextNode][3]);
        dp[u][3] += t;
        sum += t;
        minA = min(minA, dp[nextNode][2] - t);
    }
    sum += minA;
    dp[u][1] = min(dp[u][1], sum);
}

int main(int argc, char const *argv[])
{
    /* code */
    //int n;
    while(scanf("%d%d%d",&n, &c1, &c2) && n != 0) {
        int x, y;
        for(int i = 0; i < 10001; i++) GR[i].clear();
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            GR[x].push_back(y);
            GR[y].push_back(x);
        }
        memset(dp, 0, sizeof(dp));
        dfs(1, -1);
        cout << min(dp[1][0], min(dp[1][2], dp[1][1])) << endl;
    }
    return 0;
}
