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

bool isInterleavingRec(string a, string b, string c, int ai, int bi, int ci) {
  if(!(a.size() != 0 || b.size() != 0 || c.size() != 0)) return true;
  if(c.size() < ci) return false;
  return ((a[ai] == c[ci] && isInterleavingRec(a, b, c, ai + 1 , bi + 1, ci + 1))
   || (b[bi] == c[ci] && isInterleavingRec(a, b, c, ai, bi + 1, ci + 1)));
}

bool isInterleavingDp(string a, string b, string c) {
  int M = a.size();
  int N = b.size();
  if(c.size() != (M + N)) return false;
  bool dp[M+1][N+1];
  memset(dp, false, sizeof(dp));
  for(int i = 0; i <= M; i++) {
    for(int j = 0; j <= N; j++) {
      if(i == 0 && j == 0) {
        dp[i][j] = true;
      } else if (i == 0 && b[j - 1] == c[i + j - 1]) {
        dp[i][j] = dp[i][j-1];
      } else if (j == 0 && a[i - 1] == c[i + j - 1]) {
        dp[i][j] = dp[i-1][j];
      }

      //regular matching of string
      if(a[i-1] == c[i+j -1] && b[j-1] == c[i+j-1]) {
        dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
      } else if(a[i-1] == c[i+j -1]) {
        dp[i][j] = dp[i-1][j];
      } else if(b[j-1] == c[i+j -1]) {
        dp[i][j] = dp[i][j-1];
      }
    }
  }
  return dp[M][N];
}
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  cout << isInterleavingDp(a, b, c) << endl;

}
