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

vector<vector<int>> findPowerSet(vector<int> a, int index) {
  if(a.size() == 0 || index == a.size()) {
    vector<vector<int>> ps;
    vector<int> v;
    ps.pb(v);
    return ps;
  }
  vector<vector<int>> ps1 = findPowerSet(a, index + 1);
  vector<vector<int>> ps2;
  int currVal = a[index];
  fri(i, ps1.size()) {
    vector<int> ss = ps1[i];
    ps1[i].pb(currVal);
    ps2.pb(ss);
  }
  ps1.insert(ps1.end(), ps2.begin(), ps2.end());
  return ps1;
}

vector<vector<int>> powerSetusingBinary(vector<int> a) {
  int n = a.size();
  if(n == 0) {
    vector<vector<int>> v;
    return v;
  }
  int logn = 2 << n;
  vector<vector<int>> res;
  for(int i = 0; i < logn; i++) {
    int pos = 0, j = i;
    vector<int> ss;
    while(j > 0) {
      if(j & 1) {
        ss.pb(a[pos]);
      }
      j = j >> 1;
      pos++;
    }
    res.pb(ss);
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  fri(i, n) cin >> v[i];
  vector<vector<int>> ps = findPowerSet(v, 0);
  cout << "Total set is " << ps.size() << endl;
  fri(i, ps.size()) {
    fri(j, ps[i].size()) {
      cout << ps[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
