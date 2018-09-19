#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <limits>
#include <functional>

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

int n, m, p, a, b;
const int inf = 1 << 30 - 1;
double dp[31][1 << 8];
int adj[31][31];
int tickets[10];

double solve(int node, int mask) {
  if(node == b) {
    return 0.0;
  }
  if(dp[node][mask] != -1) {
    return dp[node][mask];
  }
  dp[node][mask] = inf;
  fir(i, m) {
    if(adj[node][i] == -1) continue;
    fri(j, n) {
      int newMask = mask | (1 << j);
      dp[node][mask] = min(dp[node][mask],
        adj[node][i]/ static_cast<double>(tickets[j]) + solve(i, newMask));
    }
  }
  return dp[node][mask];
}

int main() {
    while(1) {
      cin >> n >> m >> p >> a >> b;
      if(n == m&&m == p&&p == a&&a == b&&b == 0) break;
      fri(i, 31){
        fri(j, 31) adj[i][j] = -1;
      }
      fri(i, 31) {
        fri(j, 1 << 8) {
          dp[i][j] = -1;
        }
      }
      fri(i, n) {
        cin >> tickets[i];
      }
      a--;
      b--;
      fri(i, p) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x-1][y-1] = z;
        adj[y-1][x-1] = z;
      }
      dp[a][0] = 0;
      cout << solve(a, 0) << endl;
    }
    return 0;
}
