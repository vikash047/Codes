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

const int MAXM = 2505;
const int MAXN = 55;
int n;
int has[MAXM][MAXN], dp[MAXM][MAXN];
int plates[MAXM];

int main(int argc, char const *argv[])
{
    /* code */
    while(scanf("%d", &n) == 1) {
        vector<pii> D;
        int height[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> height[i];
            for(int j = 0; j < height[i]; j++) {
                int x;
                cin >> x;
                D.push_back(mp(x, i));
            }
        }
        sort(D.begin(), D.end());
        D.resize(unique(D.begin(), D.end()) - D.begin()); // remove all same elements;
        int M = 1;
        for(int i = 0; i < D.size(); i++) {
            int j = i;
            int cnt = 0;
            while(j < D.size() && D[i].ff == D[j].ff) {
                has[M][D[i].ss] = 1;
                j++;
                cnt++;
            }
            plates[M] = cnt; // unique number of plates in diff piles
            M++;
            i = j - 1;
        }
        for(int i = 0; i <= n; i++) {
            if(has[1][i]) 
                dp[1][i] = paltes[1];
        }
        for(int i = 2; i <= M; i++) {
            for(int j = 1; j <= n; j++) {
                if(!has[i][j]) continue;
                for(int k = 1; k <= n; k++) {
                    if(has[i][k] && (j != k || plates[i] == 1)) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + plates[i] - 1);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + plates[i]);
                    }
                }
            }
        }
        int ret = INT_MAX;
        for(int i = 1; i <= n; i++) {
            ret = min(dp[M][i], ret);
        }
        cout << (2*ret - n - 1) << endl;
    }
    return 0;
}
