/**
 * MINUS Solution by Deon Nicholas (dojiboy9)
 *
 * Treat the problem like a modified knapsack problem.
 * Try to place + and - signs between each pair of adjacent numbers
 * so that the sum is M.
 *
 * You can prove that a solution is valid (achievable by the sequence
 * of operations specified in the problem statement) if and only if
 * the first sign is a "-".
 *
 * You can recover the "sequence of steps" needed to make this happen
 * (and hence prove that this is always possible) by considering
 * the right-most "-" sign in the knapsack solution. You will recurse
 * on everything to the left of this sign, and "negate" everything
 * to the right.
 *
 * See the example below.
 */

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)

#define MAXN 102
#define MAXM 502
#define MAXS 10002
#define DELTA 10002

#define DUNNO (-1)
#define IMPOSSIBLE 999

// dp[n][s] :=
//    The right-most minus-sign in a "knapsack" solution among the
//    first n numbers, if trying to sum to s (where s can be negative).
//
//    If dp[n][s] = k, then the k^{th} sign is a "-", and (k+1),(k+2),...
//    are all "+".
//
//    e.g.: if given [3,7,4,6,2,3], and 3 - 7 + 4 - 6 + 2 + 3 = -1
//          then n = 6, s = -1, and dp[6][-1] = 2 (since sign 2 is the
//          right-most "negative" sign, zero-indexed).
//
//          To recover the sequence, "negate" everything after the right-most
//          "-" sign, and then recurse on everything to the left.
//
//      So:   3 - 7 + 4 - 6 + 2 + 3
//          = 3 - 7 + 4 - (6 - 2 - 3)
//          = 3 - 7 + 4 - ((6 - 2) - 3)
//          = (3 - 7 + 4) - ((6 - 2) - 3)
//            ^_________^ - ^___________^
//              recurse         easy
//
//      where the last part: ((6 - 2) - 3) is in a form that matches the
//      MINUS operation of the problem statement.
int dp[MAXN][MAXS + DELTA]; 


int A[MAXN];    // A is the original array
int S[MAXN];    // S[i] := A[0] + A[1] + ... + A[i]

int sum(int i, int j) {
  if (i > j) return 0;
  return S[j] - (i?S[i-1]:0);
}


// Compute the dp by trying to recursively pick the right-most "-" sign
int solve(int n, int s) {
  int& ans = dp[n][s + DELTA];
  if (ans >= 0) return ans;
  if (n==0) return ans = (s==0?0:IMPOSSIBLE);
  if (n==1) return ans = (s==A[0]?0:IMPOSSIBLE);
  ans = IMPOSSIBLE;

  // pick the location of the right-most negative sign
  FOR(k,n-1) {
    int rest = A[k+1] - sum(k+2, n-1);  // sum of everything after the "-"
    int here = solve(k+1, s + rest);    // solution to everything before "-"

    if (here != IMPOSSIBLE) {           // if it works, we're done
      ans = k;
      break;
    }
  }
  return ans;
}


// Print the final solution (sequence of steps)
//
// Simulate the dp. At each step, we pick the index of the right-most
// "-" sign (as returned by solve(n,s)). Given this, we split, recurse
// on the left side (returning the actual sequence of operations),
// then append the obvious operations on the right side, and finally
// apply the final "-" operation
vector<int> print_solve(int n, int s) {
  int k = solve(n,s);
  assert(k != IMPOSSIBLE);

  if (n==1) return {};

  int rest = A[k+1] - sum(k+2, n-1);
  auto ans = print_solve(k+1, s + rest);
  FORALL(_,k+1,n-2) {
    ans.push_back(1);
  }
  ans.push_back(0);
  return ans;
}


int main() {
  int TEST;
  scanf("%d",&TEST);
  FOR(test,TEST) {
    memset(dp,DUNNO,sizeof(dp));
    memset(A,0,sizeof(A));
    memset(S,0,sizeof(S));

    int N,M;
    scanf("%d%d",&N,&M);
    FOR(i,N) scanf("%d",&A[i]);
    FOR(i,MAXN) S[i] = A[i] + (i?S[i-1]:0);
    auto ans = print_solve(N,M);
    for (const auto & p : ans) {
      printf("%d\n",p+1);
    }
    printf("\n");
  }
}

















