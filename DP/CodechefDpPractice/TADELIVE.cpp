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

int dpSol(int a[], int b[], int n, int x, int y) {
  int dp[n+1][x+1];
  memset(dp, 0, sizeof(dp));
  frei(i, 1, n) {
    for(int j = 1; j <= x && j <= i; j++) {
      int any = 0;
      if(j <= x) {
        any = dp[i-1][j-1] + a[i];
      }
      int bob = 0;
      if(i - j <= y) {
        bob += dp[i-1][j] + b[i];
      }
      dp[i][j] = max(any, bob);
    }
  }
  int res = 0;
  frei(i, 0, x) {
    res = max(res, dp[n][i]);
  }
  return res;
}

int main()  {
  int n, x, y;
  cin >> n >> x >> y;
  int64 lres = 0, rres = 0;
  int a[n], b[n];
  fri(i, n) cin >> a[i];
  fri(i, n) cin >> b[i];
  int any = 0, bob = 0;
  int64 res = 0;
  fri(i, n) {
    if(a[i] > b[i]) {
      if(any + 1 <= x) {
        res += a[i];
        any++;
      } else if(bob + 1 <= y) {
        res += b[i];
        bob++;
      }
    } else {
      if(bob + 1 <= y) {
        res += b[i];
        bob++;
      } else if(any + 1 <= x) {
        res += a[i];
        any++;
      }
    }
  }
  cout << res << endl;
}
