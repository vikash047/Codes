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

bool bfs(vector<int> g[], int n, int a, int b) {
  queue<int> pq;
  bool visit[n] = {false};
  pq.push(a);
  visit[a] = true;
  while(!pq.empty()) {
    int x = pq.front();
    pq.pop();
    if(x == b) {
      return true;
    }
    if(visit[x]) continue;
    for(int i = 0; i < g[x].size(); i++) {
      int y = g[x][i];
      if(!visit[y]) {
        pq.push(y);
        visit[y] = true;
      }
    }
  }
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> g[n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
  }
  int x, y;
  cin >> x >> y;
  cout << bfs(g, x, y) << endl;
}
