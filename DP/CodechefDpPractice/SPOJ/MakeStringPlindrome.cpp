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

int makePalindrome(string s) {
  int n = s.size();
  if(n == 1) return 0;
  int dp[n][n];
  fri(i, n) dp[i][i] = 0;
  fri(i, n-1) {
    if(s[i] == s[i+1]) dp[i][i+1] = 0;
    else dp[i][i+1] = 1;
  }
  frei(l, 2, n) {
    fri(i, n-l+1) {
      int j = i + l -1;
      dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] : 1 + min(dp[i+1][j], dp[i][j-1]);
    }
  }
  return dp[0][n-1];
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    cout << makePalindrome(s) << endl;
  }
  return 0;
}
