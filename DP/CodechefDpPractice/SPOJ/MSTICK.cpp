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

struct Wood {
  int w;
  int h;
} wood[5001];

bool comp(struct Wood a, struct Wood b) {
  return (a.h > b.h) ? true : a.w < b.w;
}
int main() {
  int t;
  vector<struct Wood> ans;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    fri(i, n) {
      cin >> wood[i].w >> wood[i].h;
    }
    ans.clear();
    ans.pb(wood[0]);
    sort(wood, wood + n, comp);
    int k = 0;
    frei(i, 1, n-1) {
      if(!(wood[i].h <= ans[k].h && wood[i].w <= ans[k].w)) {
        ans.pb(wood[i]);
        k++;
      }
    }
    cout << ans.size() << endl;
  }
  return 0;
}
