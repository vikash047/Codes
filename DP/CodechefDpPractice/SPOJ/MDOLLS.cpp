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

bool comp(const pii a, const pii b) {
  return (a.ss > b.ss) ? true : a.ff < b.ff;
}
int findCeilIndex(int a[], int l, int r, int k) {
  while(r - l > 0) {
    int m = l + (r-l)/2;
    if(a[m] >= k) {
      r = m;
    }else {
      l = m;
    }
  }
  return r;
}
int LISNLOGN(vector<pii> v) {
  int n = v.size();
  if(n == 1) return n;
  int subTails[n] = {0};
  int lis = 1;
  subTails[0] = v[0].ss;
  frei(i, 1, n-1) {
    if(v[i].ss < subTails[0]) {
      subTails[0] = v[i].ss;
    } else if(v[i].ss > subTails[lis-1]) {
      subTails[lis++] = v[i].ss;
    } else {
      int ceilIndex = findCeilIndex(subTails, 0, lis-1, v[i].ss);
      subTails[ceilIndex] = v[i].ss;
    }
  }
  return lis;
}

pii dolls[20005];
int main() {
  int t;
  int m;
  int w, h;
  vector<pii> ans;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &m);
    fri(i, m) {
      scanf("%d%d", &w, &h);
      dolls[i] = mp(w,h);
    }
    sort(dolls, dolls + m, comp);
    ans.clear();
    ans.pb(dolls[0]);
    int n = m;
    frei(i, 1, n-1) {
      int lo = 0;
      int hi = ans.size() -1;
      while(hi >= lo) {
        int mid = (hi+lo)/2;
        if(ans[mid].ff > dolls[i].ff && ans[mid].ss != dolls[i].ss) {
          hi = mid - 1;
        }else {
          lo = mid + 1;
        }
      }
      if(lo == ans.size()) {
        ans.pb(dolls[i]);
      } else {
        ans[lo].ff = dolls[i].ff;
        ans[lo].ss = dolls[i].ss;
      }
    }
    printf("%d\n", ans.size());
  }
}
