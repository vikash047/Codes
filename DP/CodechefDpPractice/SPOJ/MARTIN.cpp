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

int sum[2][503][503];
int dp[503][503];
int n, m;

int main() {
    int k;
    while(1) {
      cin >> n >> m;
      if(n+m == 0) break;
      fri(i, n) {
        fri(j, m) {
          cin >> k;
          if(j > 0) sum[1][i][j] += k + sum[1][i][j-1];
          else sum[1][i][j] = k;
        }
      }
      fri(i, n) {
        fri(j, m) {
          cin >> k;
          if(i > 0) sum[0][i][j] += k + sum[0][i-1][j];
          else sum[0][i][j] = k;
        }
      }
      fri(i, n) {
        fri(j, m) {
          int temp1 = sum[1][i][j];
          int temp2 = sum[0][i][j];
          if(i > 0) temp2 += dp[i-1][j];
          if(j > 0) temp1 += dp[i][j-1];
          temp1 = max(temp1, temp2);
          dp[i][j] = temp1;
        }
      }
      cout << dp[n-1][m-1] << endl;
    }
}
