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

int dpWithBit(int a[], int n, int k) {
  if(n == 0) return k;
  int dp[n+1][1024];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  frei(i, 1, n) {
    fri(j,1024) {
      dp[i][j] = (dp[i-1][j] == 1 || dp[i-1][j^a[i-1]] == 1) ? 1 : 0;
      // till A[1..i-1] any subset which gives j^a[i] bc F(p)^a[i] = j
    }
  }
  int mx = 0;
  fri(i, 1024){
    if(dp[n][i]) mx = max(mx, i^k);
  }
  return mx;
}

pair<vector<int>, int> dpUsingPowerSet(int a[], int n, int index, int k) {
  if(n == 0) {
    vector<int> v(1,k);
    return mp(v,k);
  }
  if(index == n) {
    vector<int>v(1,k);
    return mp(v,k);
  }
  pair<vector<int>, int> ps1 = dpUsingPowerSet(a, n, index + 1, k);
  vector<int> ps2;
  int mx = ps1.ss;
  int currVal = a[index];
  fri(i, ps1.ff.size()) {
    ps2.pb(ps1.ff[i]);
    ps1.ff[i] = ps1.ff[i]^currVal;
    mx = max(mx, ps1.ff[i]);
  }
  fri(i, ps2.size()) {
    ps1.ff.pb(ps2[i]);
  }
  return mp(ps1.ff, mx);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    fri(i, n) cin >> a[i];
    cout << dpWithBit(a, n, k) << endl;
  }
  return 0;
}

int function(int x)  {
  int a[x];
  int a[0] = 0;
  int a[1] = 1;
  int j = 1;
  while(a[j] <= x) {
     a[++j] = a[j-1] + a[j-2];
  }
  return a[j];
}
