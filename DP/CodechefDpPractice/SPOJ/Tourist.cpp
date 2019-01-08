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
#define INF 1000111222
#define eps 1e-7
#define maxN 5005

int n, m;
int grid[101][101];
int visit[101][101];
int dp1[101][101];
int dp2[101][101];



void clear() {
    frei(i, 0, 101) {
        frei(j, 0, 101) {
            grid[i][j] = visit[i][j] = dp1[i][j] = dp2[i][j] = 0;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        string s;
        fri(i, n) {
            cin >> s;
            fri(j, m) {
                if(s[j] == '*') {
                    grid[i][j] = 1;
                    dp1[i][j] = dp2[i][j] = 1;
                } else if(s[j] == '#') {
                    grid[i][j] = -1;
                    dp1[i][j] = dp2[i][j] = -1;
                } else {
                    grid[i][j] = 0;
                    dp1[i][j] = dp2[i][j] = 0;
                }       
            }
        }

    }
}