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

void print(int* a, int n) {
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << *((a+n*i)+j) << " ";
    }
    cout << endl;
  }
}

int minCut(string s) {
  if(s.size() == 0) return 0;
  bool isPalindrome[s.size()][s.size()];
  memset(isPalindrome, false, sizeof(isPalindrome));
  for(int i = 0; i < s.size(); i++) isPalindrome[i][i] = true;
  for(int i = 0; i < s.size() - 1; i++) {
    if(s[i] == s[i+1]) isPalindrome[i][i+1] = true;
  }
  for(int l = 3; l < s.size(); l++) {
    for(int i = 0; i < s.size() - l + 1; i++) {
      int j = i + l - 1;
      if(s[i] == s[j]) isPalindrome[i][j] = isPalindrome[i+1][j-1];
      else isPalindrome[i][j] = false;
    }
  }
  //print boolean array
  cout << "Print substrings palindrome array" << endl;
  int n = s.size();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << isPalindrome[i][j] << " ";
    }
    cout << endl;
  }
  cout << "finish array" << endl;
  int cut[n][n];
  memset(cut, n - 1, sizeof(cut));
  cut[0][s.size() - 1] = s.size() - 1;
  for(int i = 0; i < n; i++) {
    if(isPalindrome[0][i]) {
      cut[0][i] = 0;
    } else {
      for(int j = 0; j < i; j++) {
         if(isPalindrome[j][i]) {
           int sol = 1 + cut[0][j-1];
           if(sol < cut[0][i]) {
             cut[0][i] = sol;
           }
         }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << cut[i][j] << " ";
    }
    cout << endl;
  }
  return cut[0][s.size()-1];
}

int main() {
  string s;
  cin >> s;
  cout << minCut(s) << endl;
}
