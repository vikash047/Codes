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
#define pr pair

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

const int maxk = 1001;
const int maxn = 5001;
int DP[maxk][maxn];
int BAD[maxn];
bool comp(int a, int b) {
    return a > b;
}

int solve(int k, int n) {
    if(DP[k][n] != -1) {
        return DP[k][n];
    }
    if(n < 3*k) {
        DP[k][n] = INT_MAX;
    }
    else if(k == 0) {
        DP[k][n] = 0;
    } else {
        DP[k][n] = min(solve(k, n-1), solve(k-1, n-2) + BAD[n]);
    }
    return DP[k][n];
}

int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
     while(t--){
        int k, n;
        cin >> k >> n;
        k = k + 8;
        vector<int> L(n, 0);
        for(int j = 0; j < n; j++) {
            cin >> L[j];
        }
        
        sort(L.begin(), L.end(), comp);
        for(int i = 1; i < n; i++) {
            BAD[i+1] = (L[i-1] - L[i])*(L[i-1] - L[i]);
        }
        memset(DP, -1, sizeof(DP));
        int ans = solve(k, n);
    }
    return 0;
}
