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


int solution(string ex[], string op[], int n, int m) {
  bool lop[3] = {false};
  for(int i = 0; i < m; i++) {
    if(op[i] == "|") lop[0] = true;
    if(op[i] == "&") lop[1] = true;
    if(op[i] == "^") lop[2] = true;
  }
  int T[n][n], F[n][n];
  for(int i = 0; i < n; i++) {
    T[i][i] = (ex[i] == "T") ? 1 : 0;
    F[i][i] = (ex[i] == "F") ? 1 : 0;
  }
  for(int gap = 1; gap < n; gap++) {
    for(int i = 0, j = gap; j < n; i++, j++)  {
      T[i][j] = F[i][j] = 0;
      for(int k = i; k < j; k++) {
        T[i][j] = (
          (lop[0] ? (T[i][k]*T[k+1][j] + T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j]) : 0)
          +
          (lop[1] ? (T[i][k]*T[k+1][j]): 0)
          +
          (lop[2] ? (T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j]): 0)
        );
        F[i][j] = (
          (lop[0] ? (F[i][k]*F[k+1][j]) : 0)
          +
          (lop[1] ? (F[i][k]*F[k+1][j] + T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j]): 0)
          +
          (lop[2] ? (T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]): 0)
        );
      }
    }
  }
  return T[0][n-1];
}

int main() {
  int n, m;
  cin >> n >> m;
  string ex[n], op[m];
  for(int i = 0; i < n; i++) cin >> ex[i];
  for(int i = 0; i < m; i++) cin >> op[i];
  cout << solution(ex, op, n, m) << endl;
  return 0;
}
