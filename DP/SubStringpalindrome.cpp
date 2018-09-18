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
string findMaxInArray(string s, int dp[], int m, int n);

string preProcess(string s) {
  if(s.size() == 0) {
    return "^$";
  }
  string ret = "^";
  for(int i = 0; i < s.size(); i++) {
    string temp = s.substr(i,1);
  //  cout << temp << endl;
    ret += ("#" + temp);
  }
  //cout << "end" << endl << endl;
  ret += "#$";
  //cout << ret << endl;
  //cout << ret.size() << endl;
  return ret;
}

string findPalindrome(string s) {
  int n = s.size();
  string T = preProcess(s);
  int m = T.size();
  int dp[m] = {0};
  int prevEnd = 0;
  int prevC = 0;
  for(int i = 1; i < m-1; i++) {
     int i_m = prevC - (i - prevC);
     dp[i] = (i < prevEnd) ? min(dp[i_m], prevEnd - i) : 0;
     while(T[i+1+dp[i]] == T[i-1 - dp[i]]) dp[i]++;
     if(i + dp[i] > prevEnd) {
       prevEnd = i + dp[i];
       prevC = i;
     }
  }
  /*for(int i = 0; i < m; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;*/
  return findMaxInArray(s, dp, m, n);
}
string findMaxInArray(string s, int dp[], int m, int n) {
  int maxLen = 0;
  int centerIndex = 0;
  for(int i = 1; i < m-1; i++) {
    if(dp[i] > maxLen) {
      maxLen = dp[i];
      centerIndex = i;
    }
  }
  cout << "center " << centerIndex << " maxlen " << maxLen << endl;
  int startIndex = (centerIndex - 1 - maxLen)/2;
  cout << "startIndex " << startIndex << endl;
  return s.substr(startIndex, startIndex + maxLen);
}
int main() {
  string s;
  cin >> s;
  cout << s.size() << endl;
  cout << findPalindrome(s) << endl;
  return 0;
}
