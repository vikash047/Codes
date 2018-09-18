// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
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

vector<pair<int, int> > optimalUtilization(
                            int maximumOperatingTravelDistance,
							vector<pair<int, int> > forwardShippingRouteList,
							vector<pair<int, int> > returnShippingRouteList)
{
    // WRITE YOUR CODE HERE
    int m = returnShippingRouteList.size();
    int n = forwardShippingRouteList.size();
    int p[n][m];
    for(int i = 0; i < forwardShippingRouteList.size(); i++) {
        for(int j = 0; j < returnShippingRouteList.size(); j++) {
            p[i][j] = (forwardShippingRouteList[i].second + returnShippingRouteList[j].second);
        }
    }
    int tp = n*m;
    bool dp[tp+1][maximumOperatingTravelDistance+1];
    dp[0][0] = true;
    memset(dp, false, sizeof(dp));
    for(int i = 1; i <= maximumOperatingTravelDistance; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < m; k++){
                cout << p[j-1][(j-1)*m+k] << endl;
                if(p[j-1][(j-1)*m+k] <= i) {
                    dp[(j-1)*m+k][i] = dp[(j-1)*m+k-1][i] || dp[(j-1)*m+k-1][i - p[j-1][j*m+k]];
                }
            }
        }
    }
    vector<pair<int,int>> res;
    int i = tp;
    int j = maximumOperatingTravelDistance;
    for(int i = 0; i <= maximumOperatingTravelDistance; i++) {
      for(int j = 0; j <= tp; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    while(i <= 1 && j <= 1) {
        if(dp[i][j]) {
            int fd = i%m == 0 ? i/m : i/m + 1;
            int rd = m - (fd*m - i);
            res.push_back(make_pair(forwardShippingRouteList[fd].first, returnShippingRouteList[rd].first));
            j = j - p[fd][m*fd+rd];
        }
        i--;
    }
    return res;

}
int main() {
  vector<pair<int, int>> f;
  vector<pair<int, int>> r;
  int n, m;
  cin >> n >> m;
  int mxop;
  fri(i, n){
    int a, b;
    cin >> a >> b;
    f.pb(mp(a, b));
  }
  fri(i, m){
    int a, b;
    cin >> a >> b;
    r.pb(mp(a, b));
  }
  cin >> mxop;
  std::vector<pair<int, int>> v = optimalUtilization(mxop, f, r);
  for(int i = 0; i < v.size(); i++) {
    cout << v[i].ff << " " << v[i].ss << endl;
  }
  return 0;
}
// FUNCTION SIGNATURE ENDS
