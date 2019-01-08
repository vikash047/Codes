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

class FindPath {
public:
  map<string, vector<string>> smallWords;
  vector<string> dict;
  set<string> dictSet;
  map<string, vector<string>> mapTOpath;
  set<string> visit;
  vector<string> convertDFS(string a, string b) {
    vector<string> existingPath = mapTOpath[a];
    if(existingPath.size() > 0) {
      return existingPath;
    }
    if(visit.count(a) > 0) return existingPath;
    visit.insert(a);
    vector<string> minPath;
    for(int i = 0; i < a.length(); i++) {
      string temp = a.substr(0, i) + a.substr(i + 1, a.lenght()) + i;
      for(string ss : smallWords[temp]) {
        if(ss == b) {
          vector<string> res;
          res.pb(a);
          mapTOpath[temp] = res;
          return res;
        }
        if(ss == a) continue;
        vector<string> fpath = convertDFS(ss, b);
        if(minPath.size() == 0 || minPath.size() > 1 + fpath.size()) {
          minPath.clear();
          minPath.pb(ss);
          minPath.pb(fpath);
        }
      }
    }
    return minPath;
  }
  void breakIntoSmallerword() {
    for(string ss : dict) {
      for(int i = 0; i < ss.size(); i++) {
        string temp = ss.substr(0, i) + ss.substr(i + 1, ss.size()) + i;
        if(smallWords.count(temp) > 0) {
          vector<string> temp;
          temp.pb(ss);
          smallWords[temp] = temp;
        } else {
          smallWords[temp].pb(ss);
        }
      }
    }
  }

  // complexity is n^2*m
  int bfs(string a, string b) {
    queue<pair<string, int>> pq;
    pq.push(mp(a, 1));
    while(!pq.empty()) {
      pair<string, int> fp = pq.front();
      pq.pop_front();
      if(fp.ff == b) {
        return fp.ss;
      }
      for(string ss : dict) {
        if(isAdj(ss, fp.ff)) {
          pq.push(mp(ss, fp.ss + 1));
        }
      }
    }
    return INT_MAX;
  }
  bool isAdj(string a, string b) {
    int count = 0;
    for(int i = 0; i < a.size(); i++) {
      if(a[i] != b[i]) count++;
      if(count > 1) return false;
    }
    return (count == 1 ? true : false);
  }
}

int main() {

}
