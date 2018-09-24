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

int n, m, kch;
char str[104][104];
unsigned dp[104][104];

bool get(int x, int bit) {
    return (x >> bit)&1;
}

void setBit(int &x, int bit) {
    x += (1 << bit);
}

int main() {
    cin >> n >> m >> kch;
    frei(i, 1, n) {
        scanf("%s", &str[i][1]);
    }
    int s, k, ans = 0;
    frei(y, 1, n) {
        frei(x, 1, m) {
            frei(h, 1, n - y + 1) {
                frei(w, 1, m - x + 1) {
                    s = dp[h-1][w] | dp[h][w-1];
                    k = __builtin_popcount(s);
                    if(!get(s, str[y + h - 1][x + w -1] - 'A')) {
                        k++;
                        setBit(s, str[y + h - 1][x + w -1] - 'A');
                    }
                    dp[h][w] = s;
                    if(k == kch) ans++;
                    if(k > kch) break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}