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
const int inf = 1e9;

int findMax(int n, int a[]) {
  int64 mx = 0;
  fri(i, n) {
    mx = max(mx, (int64)a[i]);
  }
  return mx;
}

int64 dp2d(int n, int h[], int k[]) {
  int hmax = findMax(n, h);
  int64 dp[n+1][2*hmax+1];
  frei(i, 0, n) dp[0][i] = inf;
  dp[0][0] = 0;
  frei(i, 1, n){
    frei(s, 0, 2*hmax) {
      dp[i][s] = dp[i-1][s];
      if(k[i] >= s) {
        dp[i][s] = min(1+dp[i-1][s-k[i]], dp[i-1][s]);
      }
    }
  }
  int64 res = 0;
  fri(i,n) {
    res += dp[n][2*h[i]];
  }
  return res;
}

int64 dp1db(int n, int h[], int k[]) {
  int hmax = findMax(n, h);
  int64 dp[2*hmax+1];
  dp[0] = 0;
  frei(i, 1, 2*hmax) dp[i] = inf;
  frei(s, 1, 2*hmax) {
    fri(i, n) {
      if(k[i] <= s) {
        dp[s] = min(1+dp[s-k[i]], dp[s]);
      }
    }
  }
  int64 res = 0;
  fri(i,n) {
    res += dp[2*h[i]];
  }
  return res;
}

int64 dp1df(int n, int h[], int k[]) {
  int hmax = findMax(n,h);
  int dp[2*hmax+1];
  dp[0] = 0;
  frei(i, 1, 2*hmax) dp[i] = inf;
  fri(i, n) {
    frei(s, 0, s+k[i]) {
      dp[s+k[i]] = min(1 + dp[s], dp[s+k[i]]);
    }
  }
  int64 res = 0;
  fri(i, n) {
    res += dp[2*h[i]];
  }
  return res;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int h[n], k[n];
    fri(i, n) cin >> h[i];
    fri(i, n) cin >> k[i];
    cout << dp1db(n, h, k) << endl;
  }
}
