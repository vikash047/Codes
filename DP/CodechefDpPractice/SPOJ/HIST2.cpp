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


void solve(int a[], int n) {
  //if(n == 1) return;
  int64 tp = 1 << n;
  int64 premiter[tp][n];
  int64 count[tp][n];
  fri(i, tp) {
    fri(j, n) {
      premiter[i][j] = 0;
      count[i][j] = 0;
    }
  }
  fri(i, n) {
    premiter[1 << i][i] = 2*a[i] + 2;
    count[1<<i][i] = 1;
  }

  frei(i, 3, tp) {
    fri(j, n) {
      if(i & (1 << j)) {
        int64 tempmax = 2*a[j] + 2;
        fri(k, n) {
          if((i - (1 << j)&(1 << k)) != 0) {
            if(a[j] < a[k]) {
              tempmax = max(tempmax, premiter[i - (1 << j)][k] + 2);
            } else {
              tempmax = max(tempmax, premiter[i - (1 << j)][k] + 2*abs(a[k] - a[j]) + 2);
            }
          }
        }
        premiter[i][j] = tempmax;
        int64 c = 0;
        fri(k, n) {
          if((i - (1 << j) & (1 << k)) != 0) {
            if(a[j] < a[k]) {
              if((premiter[i - (1 << j)][k] + 2) == tempmax) {
                count[i][j] += count[i - (1 << j)][k];
              }
            } else {
              if((premiter[i - (1 << j)][k] + 2*abs(a[k] - a[j]) + 2) == tempmax) {
                count[i][j] += count[i - (1 << j)][k];
              }
            }
          }
        }
      }
    }
  }
  int64 mm = -1;
  int64 sum = 0;
  fri(i, n) {
    mm = max(mm, premiter[tp - 1][i]);
  }
  fri(i, n) {
    if(premiter[tp - 1][i] == mm) {
      sum += count[tp - 1][i];
    }
  }
  cout << mm << " " << sum << endl;
}

int main() {
  int n;
  while(1) {
    scanf("%d", &n);
    if(n == 0) break;
    int a[n];
    fri(i, n) cin >> a[i];
    solve(a, n);
  }
  return 0;
}
