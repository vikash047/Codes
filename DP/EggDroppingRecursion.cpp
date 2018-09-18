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

int maxDroppingSteps(int eggs,  int floors) {
  if(eggs == 1) return floors;
  if(floors == 2) return floors;
  int minDropping = -1;
  int floorNumber = -1;
  frei(k, 1, floors-1) {
    int below = maxDroppingSteps(eggs-1, k-1);
    int above = maxDroppingSteps(eggs, floors-k);
    int maxDropingAtK = max(below, above);
    if(minDropping == -1 || minDropping > maxDropingAtK)  {
      minDropping = maxDropingAtK;
      floorNumber = k;
    }
  }
  return minDropping + 1;
}

void print(vector< vector<int> > v) {
  fri(i, v.size()) {
    fri(j, v[0].size()) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int maxDroppingDP(int eggs, int floors) {
  vector<int> v(floors+1, 0);
  vector< vector<int> > dp(eggs+1, v);
  //memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= floors; i++) dp[1][i] = i;
  for(int i = 1; i <= eggs; i++) {
    dp[i][1] = 1;
    dp[i][2] = 2;
  }
  for(int e = 2; e <= eggs; e++) {
    for(int f = 3; f <= floors; f++) {
      int minDrop = -1;
      for(int x = 1; x <= f; x++) {
        int mxd = 1 + max(dp[e-1][x-1], dp[e][f-x]);
        if(minDrop == -1 || minDrop > mxd) {
          dp[e][f] = mxd;
          minDrop = mxd;
        }
      }
    }
    print(dp);
  }
  return dp[eggs][floors];
}

int main() {
  int eggs, floors;
  cin >> eggs >> floors;
  cout << maxDroppingDP(eggs, floors) << endl;
}
