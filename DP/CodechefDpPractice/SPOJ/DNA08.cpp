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

int main() {
  int k;
  while(true) {
    scanf("%d", &k);
    if(k == 0) break;
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    int dp[n+1][m+1];
    fri(i, n+1) {
      fri(j, m+1) {
        dp[i][j] = 0;
        if(i == 0 || j == 0) continue;
        int c = 1;
        while(i - c >= 0 && j - c >= 0 && s1[i-c] == s2[j-c]) {
          if(c >= k) {
            dp[i][j] = max(dp[i][j], c + dp[i-c][j-c]);
          }
          c++;
        }
        dp[i][j] = max(dp[i][j], dp[i][j-1]);
        dp[i][j] = max(dp[i][j], dp[i-1][j]);
      }
    }
    cout << dp[n][m] << endl;
  }
}
