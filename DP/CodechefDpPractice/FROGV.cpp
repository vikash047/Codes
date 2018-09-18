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

bool comp(pii a, pii b) {
  return a.ss < b.ss;
}
int main() {
  int n, k, p;
  cin >> n >> k >> p;
  vector<pii> v(n);
  fri(i, n) {
    int x;
    cin >> x;
    v[i] = mp(i+1, x);
  }
  sort(v.begin(), v.end(), comp);
  int a[n+1];
  a[1] = 0;
  int index[n+1];
  index[v[0].ff] = 0;
  frei(i, 1, v.size()-1) {
    a[i+1] = (v[i].ss - v[i-1].ss) <= k ? a[i] : a[i] + 1;
    index[v[i].ff] = i;
  }
  // frei(i, 1, n) {
  //   cout << a[i] << " index in v "  << index[i] << endl;
  // }
  fri(i, p) {
    int x, y;
    cin >> x >> y;
    if(a[index[x]+1] != a[index[y]+1]) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
