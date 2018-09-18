#include<bits/stdc++.h>
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
int per[4] = {1, 2, 3, 4};
int ord[5][105], seq[105], aux[105];
int u[5], v[105];

int listnlogn(int a[], int n) {
  if(n == 1) return a[0];
  int u, v, sbz = 0;
  aux[sbz++] = 0;
  frei(i, 1, n-1) {
    if(a[i] > a[aux[sbz-1]]) {
      aux[sbz++] = i;
      continue;
    }
    for(u = 0, v = sbz-1; u < v;) {
      int m = (u+v) >> 1;
      if(a[aux[m]] < a[i]) {
        u = m+1;
      } else {
        v = m;
      }
    }
    if(a[aux[u]] < a[i]) a[aux[u]] = i;
  }
  return sbz;
}

int main() {
  int c, n;
  scanf("%d%d", &c, &n);
  int t = c*n;
  fri(i, t) {
    scanf("%d%d", &u[i], &v[i]);
  }
  int mn = 1 << 30;
  do {
    int cnt = 0;
    fri(i, c) {
      frei(j, 1, n) ord[per[i]][j] = ++cnt;
    }
    fri(i, t) seq[i] = ord[u[i]][v[i]];
    mn = min(mn, t - listnlogn(seq, t));
  } while (next_permutation(per, per + c));
  printf("%d\n", mn);
  return 0;
}
