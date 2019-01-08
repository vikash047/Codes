#include <bits/stdc++.h>

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
#define eps 1e-7
#define maxN 5005

void Floyd(int64 dist[][101], int n) {
  fri(i, n) dist[i][i] = 0;
  fri(k, n) {
    fri(i, n) {
      fri(j, n) {
        if(dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

int PathLength(int dist[][101], int n, vii task, int start) {
  cout << n << "  " << start << endl;
  int tsize = task.size();
  int total = 1 << tsize;
  vector<int> tras[total - 1];

  frei(i, 1, total -1) {
    int temp = i, counter = 0;
    while(temp) {
      if(temp & 1) {
        tras[i-1].pb(counter);
      }
      counter++;
      temp = temp >> 1;
    }
  }

  int op[5000][101];
  fri(i, n) op[0][i] = dist[start][i];
  frei(i, 1, tsize) {
    frei(j, 1, total-1) {
        if(tras[j-1].size() == i) {
          fri(s, n) {
            int best = 2147483647;
            fri(k, i) {
              int currtask = tras[j-1][k];
              int rest = 1 << currtask;
              rest = j - rest;
              int temp = op[rest][task[currtask].second] +
               dist[task[currtask].first][s]
                + dist[task[currtask].first][task[currtask].second];
              best = min(temp, best);
            }
            op[j][s] = best;
           // cout << best << endl;
          }
        }
    }
  }
  return op[total - 1][start];
}

int g[101][101];
int64 dist[101][101];
int64 dp[1 << 12][101];
int n, m, s, msk = 0;
const int INF = 2147483647;
vii task;

int64 solve(int mask, int prev) {
  if(dp[mask][prev] != -1) return dp[mask][prev];
  int64 ans = INF, cost, f = 0;
  //cout << msk << "  " << mask << "  " << prev << endl; 
  fri(i, msk) {
    if(!(mask & (1 << i))) {
      f = 1;
      cost =  dist[prev][task[i].first] + dist[task[i].first][task[i].second] + solve(mask | (1 << i), task[i].second);
      //cout << cost << endl;
      if(cost < ans) {
        ans = cost;
      } 
    }
  }
  if(f == 0) return dp[mask][prev] = dp[mask][s-1];
  else return dp[mask][prev] = ans;

}

void clear() {
  fri(i, n) dist[i][i] = 0;
  for(int i=0;i<101;i++)for(int j=0;j<101;j++)dist[i][j]=INF;
  memset(g, -1, sizeof(g));
  memset(dp, -1, sizeof(dp));
  task.clear();
}

int main() {
  int t;
  cin >> t;
  while(t--) {
      cin >> n >> m >> s;
      clear();
      int x, y, w;
      fri(i, m) {
        cin >> x >> y >> w;
        g[x-1][y-1] = g[y-1][x-1] = w;
        dist[x-1][y-1] = dist[y-1][x-1] = w;
      }
      Floyd(dist, n);
     /*  fri(i, n) {
        fri(j, n) {
          cout << "dist from " << i << "to " << j << "  " << dist[i][j] << " ";
        }
        cout << endl;
      } */
      int z;
      cin >> z;
      msk = 0;
      fri(i, z) {
        cin >> x >> y >> w;
        while(w--)  {
          task.pb(mp(x-1, y-1));
          msk++;
        }
      }

      cout << solve(0, s-1) << endl;
  }
  return 0;
}
