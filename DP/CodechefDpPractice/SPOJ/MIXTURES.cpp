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
#define INTMAX 2147483647

int a[105];
int dp[105][105];

int mixtures(int n) {
  if(n == 1) return 0;
  int csum[n][n];
  fri(i, n) {
    dp[i][i] = 0;
    //cout << a[i] << " ";
    csum[i][i] = a[i];
  }
  //cout << endl;
  frei(l, 2, n) {
    fri(i,n - l + 1){
      int j = l + i - 1;
      int min = INTMAX;
      for(int k = i; k < j; k++) {
        int cost = dp[i][k] + dp[k+1][j] + csum[i][k]*csum[k+1][j];
        //cout << cost << endl;
        if(cost < min) {
          dp[i][j] = cost;
          min = cost;
          csum[i][j] = (csum[i][k] + csum[k+1][j])%100;
        }
      }
    }
  }
  return dp[0][n-1];
}

int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    fri(i, n) scanf("%d", &a[i]);
    memset(dp, 0, sizeof(dp));
    cout << mixtures(n) << endl;
  }
  return 0;
}
